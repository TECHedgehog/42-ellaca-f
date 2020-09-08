/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_specs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:12:45 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/08/06 20:13:49 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

t_tab	*processor_specs(t_tab *tab)
{
	if (tab->formats[tab->i] == 'd' ||
			tab->formats[tab->i] == 'i')
		printer(processor_di(tab), tab);
	else if (tab->formats[tab->i] == 'u')
		printer(processor_u(tab), tab);
	else if (tab->formats[tab->i] == 'X' ||
				tab->formats[tab->i] == 'x')
		printer(processor_x(tab), tab);
	else if (tab->formats[tab->i] == 'p')
		printer(processor_p(tab), tab);
	else if (tab->formats[tab->i] == 'c')
		printer(processor_cs(tab), tab);
	else if (tab->formats[tab->i] == 's')
		printer(processor_cs(tab), tab);
	else if (tab->formats[tab->i] == '%')
	{
		tab->sp_percent = (tab->flag_minus < 0) ? 0 : 1;
		printer(flags_treatment(ft_strdup("%"), tab), tab);
	}
	tab->i++;
	return (tab);
}
