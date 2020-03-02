/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:03:11 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/02/26 20:11:30 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*tab_initializer(t_tab *tab)
{
	tab->f_copy = (char *)tab->formats;
	tab->f_copy2 = (char *)tab->formats;
	tab->len = 0;
	tab->i = 0;
	tab->j = 0;
	tab->specifiers = "cspdiuxX%";
	tab->punt_spec = NULL;
	tab->flags = "-0.*123456789";
	tab->flag_minus = -1;
	tab->flag_zero = -1;
	tab->flag_precision = -1;
	tab->flag_star = -1;
	tab->flag_width = 0;
	return (tab);
}
