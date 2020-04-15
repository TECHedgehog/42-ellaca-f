/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_width_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:42:53 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/03/02 18:32:15 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

char	*noflags_negative(char *str, t_tab *tab)
{
	int		i;
	char	*s_aux;

	i = 1;
	s_aux = str;
	if (tab->is_negative)
	{
		if (!(str = (char*)malloc(ft_strlen(s_aux) + 2)))
			return (0);
		str[0] = '-';
		while (i < (int)(ft_strlen(s_aux) + 1))
		{
			str[i] = s_aux[i - 1];
			i++;
		}
		str[i] = '\0';
		free(s_aux);		
	}
	return (str);
}

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
		while (tab->flag_width > 0)
		{
			str[tab->j++] = '0';
			tab->flag_width--;
		}
		while (aux > tab->j)
		{
			str[tab->j] = tab->s_flags[tab->k++];
			tab->j++;
		}
		free(tab->s_flags);
	}
	return (str);
}

char	*di_width_treatment(char *str, t_tab *tab)
{
	size_t aux;

	aux = tab->flag_width;
	tab->s_flags = str;
	if (!(str = (char*)malloc(tab->flag_width + 1)))
		return (0);
	str[tab->flag_width] = '\0';
	tab->flag_width -= ft_strlen(tab->s_flags) + tab->is_negative;
	tab->j = 0;
	while (tab->flag_width > 0)
	{
		str[tab->j++] = ' ';
		tab->flag_width--;
	}
	if (tab->is_negative)
		str[tab->j++] = '-';
	while (aux > tab->j)
	{
		str[tab->j] = tab->s_flags[tab->k++];
		tab->j++;
	}
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
			&& tab->flag_precision > (int)ft_strlen(str) + tab->is_negative)
		str = di_zero_treatment(str, tab);
	else
		str = noflags_negative(str, tab);
	return (str);
}
