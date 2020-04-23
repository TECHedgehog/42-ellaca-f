/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_treatment_di.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:42:53 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/04/23 22:21:04 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

char	*di_zero_treatment(char *str, t_tab *tab)
{
	size_t aux;

	aux = tab->flag_width;
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
		str = di_zero_minus(str, tab, aux);
		tab->k = 0;
		free(tab->s_flags);
	}
	return (str);
}

char	*di_prec_treatment(char *str, t_tab *tab)
{
	size_t aux;
	size_t index;

	aux = tab->flag_precision;
	index = tab->flag_precision;
	if (tab->flag_precision > (int)ft_strlen(str))
	{
		tab->s_flags = str;
		if (!(str = (char*)malloc(index + 1 + tab->is_negative)))
			return (0);
		if (tab->is_negative)
			str[0] = '-';
		str[index] = '\0';
		index -= (ft_strlen(tab->s_flags));
		tab->j = (tab->is_negative) ? 1 : 0;
		str = di_prec_minus(str, tab, aux, index);
		tab->k = 0;
		free(tab->s_flags);
	}
	else if (str[0] == '0' && ft_strlen(str) == 1)
		str[0] = '\0';
	else if (tab->is_negative)
		str = noflags_negative(str, tab);
	return (str);
}

char	*di_width_treatment(char *str, t_tab *tab)
{
	size_t aux;

	aux = tab->flag_width;
	tab->s_flags = str;
	tab->flag_width -= ft_strlen(tab->s_flags) + tab->is_negative;
	if (tab->flag_precision > -1)
	{
		str = di_prec_treatment(str, tab);
		tab->s_flags = str;
		tab->flag_width = aux - ft_strlen(tab->s_flags);
	}
	if (!(str = (char*)malloc(aux + 1)))
		return (0);
	str[aux] = '\0';
	tab->j = 0;
	str = di_width_minus(str, tab, aux);
	tab->k = 0;
	free(tab->s_flags);
	return (str);
}

char	*flags_treatment_di(char *str, t_tab *tab)
{
	if (tab->flag_zero > -1
		&& tab->flag_width > (int)ft_strlen(str) + tab->is_negative
		&& tab->flag_precision_pos < 0)
		str = di_zero_treatment(str, tab);
	else if (tab->flag_width > (int)ft_strlen(str) + tab->is_negative)
		str = di_width_treatment(str, tab);
	else if (tab->flag_precision_pos > -1
			&& tab->flag_precision > -1)
		str = di_prec_treatment(str, tab);
	else
		str = noflags_negative(str, tab);
	return (str);
}
