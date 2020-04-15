/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:53:24 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/04/08 11:38:38 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void		writer(t_tab *tab)
{
	write(1, &tab->formats[tab->i++], 1);
	tab->len++;
}

t_tab		*processor(t_tab *tab)
{
	while (tab->formats[tab->i] && tab->i <= ft_strlen(tab->formats))
	{
		if (tab->formats[tab->i] == '%')
		{
			tab->i++;
			while (ft_strchr(tab->flags, tab->formats[tab->i])
					&& tab->formats[tab->i])
				processor_flags(tab);
			while (ft_strchr(tab->specifiers, tab->formats[tab->i])
					&& tab->formats[tab->i])
				processor_specs(tab);
			tab->i -= 1;
		}
		else
		{
			while (tab->formats[tab->i] != '%' && tab->formats[tab->i])
				writer(tab);
			tab->i -= 1;
		}
		tab_reinitializer(tab);
		tab->i++;
	}
	return (tab);
}
