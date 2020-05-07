/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:03:11 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/05/07 10:39:22 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tab_flags_init(t_tab *tab)
{
	tab->flags = "-0.*123456789";
	tab->flags_on = 0;
	tab->flag_minus = -1;
	tab->flag_zero = -1;
	tab->flag_precision_pos = -1;
	tab->flag_precision = -1;
	tab->flag_star = -1;
	tab->flag_width = 0;
}

t_tab	*tab_initializer(t_tab *tab)
{
	tab->f_copy = (char *)tab->formats;
	tab->s_flags = NULL;
	tab->s_base = "0123456789ABCDEF";
	tab->len = 0;
	tab->i = 0;
	tab->j = 0;
	tab->k = 0;
	tab->specifiers = "cspdiuxX%";
	tab->sp_on = 0;
	tab->sp_di = 0;
	tab->sp_x = 0;
	tab->sp_c = 0;
	tab->sp_p = 0;
	tab->sp_u = 0;
	tab->sp_s = 0;
	tab->punt_spec = NULL;
	tab->is_negative = 0;
	tab->is_null = 0;
	tab->is_null_s = 0;
	tab_flags_init(tab);
	return (tab);
}
