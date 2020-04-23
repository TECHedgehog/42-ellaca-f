/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_treatment_di_aux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 22:19:43 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/04/23 22:22:12 by ellaca-f         ###   ########.fr       */
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

char	*di_zero_minus(char *str, t_tab *tab, size_t aux)
{
	while (tab->flag_width > 0)
	{
		str[tab->j++] = '0';
		tab->flag_width--;
	}
	while (aux > tab->j)
		str[tab->j++] = tab->s_flags[tab->k++];
	return (str);
}

char	*di_width_minus(char *str, t_tab *tab, size_t aux)
{
	if (tab->flag_minus < 0)
	{
		while (tab->flag_width-- > 0)
			str[tab->j++] = ' ';
		if (tab->is_negative && (tab->flag_precision < 0
			|| (tab->flag_precision < ft_strlen(tab->s_flags)
			&& tab->flag_precision < 0)))
			str[tab->j++] = '-';
		while (aux > tab->j)
			str[tab->j++] = tab->s_flags[tab->k++];
		return (str);
	}
	if (tab->is_negative && (tab->flag_precision < 0
		|| (tab->flag_precision < ft_strlen(tab->s_flags)
		&& tab->flag_precision < 0)))
		str[tab->j++] = '-';
	while ((ft_strlen(tab->s_flags) + tab->is_negative) > tab->j)
		str[tab->j++] = tab->s_flags[tab->k++];
	tab->j -= (tab->flag_precision > -1 && tab->is_negative) ? 1 : 0;
	while (tab->flag_width-- > 0)
		str[tab->j++] = ' ';
	return (str);
}

char	*di_prec_minus(char *str, t_tab *tab, size_t aux, size_t index)
{
	while (index-- > 0)
		str[tab->j++] = '0';
	while ((aux + tab->is_negative) > tab->j)
		str[tab->j++] = tab->s_flags[tab->k++];
	return (str);
}
