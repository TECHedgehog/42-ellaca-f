/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_specs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:12:45 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/02/20 18:33:35 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

t_tab	*processor_specs(t_tab *tab)
{
	if (tab->formats[tab->i] == 'd' ||
			tab->formats[tab->i] == 'i')
		processor_di(tab);
	/*else if (tab->formats[tab->i] == 'X' ||
				tab->formats[tab->i] == 'x')
		processor_x(tab);
	else if (tab->formats[tab->i] == 'c')
		processor_c(tab);
	else if (tab->formats[tab->i] == 's')
		processor_s(tab);
	else if (tab->formats[tab->i] == 'p')
		processor_p(tab);
	else if (tab->formats[tab->i] == 'u')
		processor_u(tab);
	else if (tab->formats[tab->i] == '%')
		printer("%");*/
	tab->i++;
	return (tab);
}
