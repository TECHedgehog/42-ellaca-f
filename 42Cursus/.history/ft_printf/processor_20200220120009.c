/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:53:24 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/02/20 12:00:09 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		processor(t_tab *tab)
{
	while (tab->formats[tab->len])
	{
		if (tab->formats[tab->len] == '%')
		{
			
		}
		tab->len++;
	}
}
