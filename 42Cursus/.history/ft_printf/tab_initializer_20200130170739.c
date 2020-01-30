/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:03:11 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/01/30 17:07:39 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	tab_initializer(t_tab *tab)
{
	tab->f_copy = tab->formats;
	tab->f_copy2 = tab->formats;
	tab->len = 0;
	tab->i = 0;
	tab->specifiers = "cspdiuxX%";
	tab->flags = "-0.x";
	return (tab);
}
