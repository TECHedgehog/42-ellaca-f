/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:27:59 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/08 19:59:44 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int count;
	int looplimit;
	int aux;

	count = 0;
	looplimit = size;
	while (looplimit > count)
	{
		aux = *(tab + count);
		*(tab + count) = *(tab + size - 1 - count);
		*(tab + size - 1 - count) = aux;
		looplimit--;
		count++;
	}
}
