/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:06:26 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/04/25 16:10:47 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void	processor_prec(t_tab *tab)
{
	int i;

	tab->flag_precision_pos = tab->i;
	i = tab->i + 1;
	tab->flag_precision = 0;
	while (tab->formats[i] >= '0' && tab->formats[i] <= '9')
	{
		tab->flag_precision *= 10;
		tab->flag_precision += (tab->formats[i++] - 48);
	}
	tab->i = i - 1;
}

void	processor_width(t_tab *tab)
{
	int i;

	tab->flag_width = tab->formats[tab->i] - 48;
	i = tab->i + 1;
	while (tab->formats[i] >= '0' && tab->formats[i] <= '9')
	{
		tab->flag_width *= 10;
		tab->flag_width += (tab->formats[i++] - 48);
	}
	tab->i = i - 1;
}

t_tab	*processor_flags(t_tab *tab)
{
	if (tab->formats[tab->i] == tab->flags[0])
		tab->flag_minus = tab->i;
	else if (tab->formats[tab->i] == tab->flags[1])
		tab->flag_zero = tab->i;
	else if (tab->formats[tab->i] == tab->flags[2])
		processor_prec(tab);
	else if (tab->formats[tab->i] == tab->flags[3])
		tab->flag_star = tab->i;
	else if (tab->formats[tab->i] >= '1' &&
			tab->formats[tab->i] <= '9')
		processor_width(tab);
	tab->i++;
	tab->flags_on = 1;
	return (tab);
}
