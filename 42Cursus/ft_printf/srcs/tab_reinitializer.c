/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_reinitializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:59:01 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/02/20 16:24:49 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*tab_reinitializer(t_tab *tab)
{
	tab->flag_minus = 0;
	tab->flag_zero = 0;
	tab->flag_precision = 0;
	tab->flag_star = 0;
	tab->flag_width = 0;
	return (tab);
}
