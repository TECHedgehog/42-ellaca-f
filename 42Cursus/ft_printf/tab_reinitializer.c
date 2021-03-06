/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_reinitializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:59:01 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/08/06 19:59:09 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*tab_reinitializer(t_tab *tab)
{
	tab->sp_on = 0;
	tab->sp_di = 0;
	tab->sp_x = 0;
	tab->sp_c = 0;
	tab->sp_p = 0;
	tab->sp_u = 0;
	tab->sp_s = 0;
	tab->sp_percent = 0;
	tab->flags_on = 0;
	tab->flag_minus = -1;
	tab->flag_zero = -1;
	tab->flag_precision_pos = -1;
	tab->flag_precision = -1;
	tab->flag_star = -1;
	tab->flag_width = 0;
	tab->j = 0;
	tab->is_negative = 0;
	tab->is_null = 0;
	tab->is_null_s = 0;
	tab->s_flags = NULL;
	return (tab);
}
