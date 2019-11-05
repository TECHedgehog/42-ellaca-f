/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:05:47 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/08 19:09:28 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int aux[2];
	int count;
	int looplimit;

	aux[0] = 1;
	count = 0;
	looplimit = size - 1;
	while (aux[0] != 0)
	{
		aux[0] = 0;
		while (looplimit > 0)
		{
			if (*(tab + count) > *(tab + count + 1))
			{
				aux[1] = *(tab + count);
				*(tab + count) = *(tab + count + 1);
				*(tab + count + 1) = aux[1];
				aux[0] = 1;
			}
			count++;
			looplimit--;
		}
		count = 0;
		looplimit = size - 1;
	}
}
