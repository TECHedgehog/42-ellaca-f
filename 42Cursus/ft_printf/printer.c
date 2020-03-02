/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:51:57 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/03/02 10:43:01 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

t_tab	*printer(char *str, t_tab *tab)
{
	int i;

	i = 0;
	// printf("%d\n%d\n%d\n", tab->flag_width, tab->flag_minus, tab->flag_precision);
	while (str[i])
	{
		write(1, &str[i], 1);
		tab->len++;
		i++;
	}
	// printf("\n%ld\n", tab->i);
	free(str);
	return (tab);
}
