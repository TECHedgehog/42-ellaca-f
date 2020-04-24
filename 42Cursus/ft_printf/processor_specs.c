/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_specs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:12:45 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/04/24 09:16:47 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

t_tab	*processor_specs(t_tab *tab)
{
	if (tab->formats[tab->i] == 'd' ||
			tab->formats[tab->i] == 'i')
		printer(processor_di(tab), tab);
	else if (tab->formats[tab->i] == 'X' ||
				tab->formats[tab->i] == 'x')
		printer(processor_x(tab), tab);
	/*else if (tab->formats[tab->i] == 'c')
		processor_c(tab);
	else if (tab->formats[tab->i] == 's')
		processor_s(tab);
	else if (tab->formats[tab->i] == 'p')
		processor_p(tab);
	else if (tab->formats[tab->i] == 'u')
		processor_u(tab);*/
	else if (tab->formats[tab->i] == '%')
		printer("%", tab);
	tab->i++;
	return (tab);
}
