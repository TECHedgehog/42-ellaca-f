/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:53:24 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/09/08 14:23:40 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void		writer(t_tab *tab)
{
	write(1, &tab->formats[tab->i++], 1);
	tab->len++;
}

int			sp_test(t_tab *tab)
{
	int i;

	i = (tab->formats[tab->i] == '%' && tab->sp_on > 0) ? 0 : 1;
	return (i);
}

void		searcher(t_tab *tab)
{
	tab->i++;
	while (ft_strchr(tab->flags, tab->formats[tab->i])
			&& tab->formats[tab->i])
		processor_flags(tab);
	if (ft_strchr(tab->specifiers, tab->formats[tab->i])
			&& tab->formats[tab->i] && sp_test(tab))
		processor_specs(tab);
	tab->i -= 1;
}

t_tab		*processor(t_tab *tab)
{
	while (tab->formats[tab->i] && tab->i <= ft_strlen(tab->formats))
	{
		if (tab->formats[tab->i] == '%' && tab->formats[tab->i + 1] != '%')
			searcher(tab);
		else if (tab->formats[tab->i] == '%')
		{
			tab->i++;
			while (ft_strchr(tab->flags, tab->formats[tab->i])
					&& tab->formats[tab->i])
				processor_flags(tab);
			printer(ft_strdup("%"), tab);
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
