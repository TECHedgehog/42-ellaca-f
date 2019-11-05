/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:10:25 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/07 18:04:16 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_output(int n1, int n2, int n3)
{
	if (n1 != 48 || n2 != 49 || n3 != 50)
		write(1, ", ", 2);
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, &n3, 1);
}

void	ft_print_condition(int n1, int n2, int n3)
{
	if (n1 != n2 && n2 != n3 && n1 != n3)
		ft_print_output(n1, n2, n3);
}

void	ft_print_loops(int n1, int n2, int n3)
{
	while (n1 <= 57)
	{
		while (n2 > n1 && n2 <= 57)
		{
			while (n3 > n2 && n3 <= 57)
			{
				ft_print_condition(n1, n2, n3);
				n3++;
			}
			n2++;
			n3 = n2 + 1;
		}
		n1++;
		n2 = n1 + 1;
		n3 = n2 + 1;
	}
	write(1, "\n", 1);
}

void	ft_print_comb(void)
{
	int n1;
	int n2;
	int n3;

	n1 = 48;
	n2 = 49;
	n3 = 50;
	ft_print_loops(n1, n2, n3);
}
