/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:42:53 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/05/06 20:37:05 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

char	*zero_treatment(char *str, t_tab *tab)
{
	size_t aux;

	aux = tab->flag_width;
	if (tab->sp_s)
	{
		str = width_treatment(str, tab);
		return (str);
	}
	if (tab->flag_width > ((int)ft_strlen(str) + tab->is_negative))
	{
		tab->s_flags = str;
		if (!(str = (char*)malloc(tab->flag_width + 1)))
			return (0);
		if (tab->is_negative)
			str[0] = '-';
		str[tab->flag_width] = '\0';
		tab->flag_width -= ((ft_strlen(tab->s_flags)) + tab->is_negative);
		tab->j = (tab->is_negative) ? 1 : 0;
		str = zero_minus(str, tab, aux);
		tab->k = 0;
		free(tab->s_flags);
	}
	return (str);
}

char	*prec_treatment(char *str, t_tab *tab)
{
	size_t aux;
	size_t index;

	aux = tab->flag_precision;
	index = tab->flag_precision;
	if ((tab->flag_precision > (int)ft_strlen(str) && !tab->sp_s)
		|| (tab->sp_s && tab->flag_precision <= (int)ft_strlen(str)))
	{
		tab->s_flags = str;
		if (!(str = (char*)malloc(index + 1 + tab->is_negative)))
			return (0);
		if (tab->is_negative)
			str[0] = '-';
		str[index] = '\0';
		index -= (tab->sp_s) ? index : (ft_strlen(tab->s_flags));
		tab->j = (tab->is_negative) ? 1 : 0;
		str = prec_minus(str, tab, aux, index);
		tab->k = 0;
		free(tab->s_flags);
	}
	else if ((str[0] == '0' && ft_strlen(str) == 1) || tab->is_null_s == 5)
		str[0] = '\0';
	else if (tab->is_negative)
		str = noflags_negative(str, tab);
	return (str);
}

char	*width_treatment(char *str, t_tab *tab)
{
	size_t aux;

	aux = tab->flag_width;
	tab->s_flags = str;
	tab->flag_width -= ft_strlen(tab->s_flags) + tab->is_negative;
	tab->flag_width -= tab->is_null;
	if (tab->flag_precision > -1)
	{
		str = prec_treatment(str, tab);
		tab->s_flags = str;
		tab->flag_width = aux - ft_strlen(tab->s_flags);
	}
	if (!(str = (char*)malloc(aux + 1)))
		return (0);
	str[aux] = '\0';
	tab->j = 0;
	str = width_minus(str, tab, aux);
	tab->k = 0;
	tab->flag_width = aux;
	free(tab->s_flags);
	return (str);
}

char	*flags_treatment(char *str, t_tab *tab)
{
	if (tab->flag_zero > -1
		&& tab->flag_width > (int)ft_strlen(str) + tab->is_negative
		&& tab->flag_precision_pos < 0)
		str = zero_treatment(str, tab);
	else if ((tab->flag_width > (int)ft_strlen(str) + tab->is_negative)
			|| (tab->flag_width <= (int)ft_strlen(str) && tab->sp_s == 2
			&& tab->flag_precision > -1)
			|| (tab->flag_width > 0 && (tab->flag_precision >= 0
			&& tab->flag_precision < (int)ft_strlen(str)
			&& (tab->sp_s || tab->is_null_s == 5))))
		str = width_treatment(str, tab);
	else if (tab->flag_precision_pos > -1
			&& tab->flag_precision > -1)
		str = prec_treatment(str, tab);
	else
		str = noflags_negative(str, tab);
	return (str);
}
