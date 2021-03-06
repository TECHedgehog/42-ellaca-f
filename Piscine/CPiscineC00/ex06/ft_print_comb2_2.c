/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:00:30 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/09 19:48:03 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_conditions(char *num)
{
	if (num[0] != num[2] || num[1] != num[3])
	{
		if (num[0] != '0' || num[1] != '0' || num[2] != '0' || num[3] != '1')
		{
			write(1, ", ", 2);
		}
		write(1, &num[0], 1);
		write(1, &num[1], 1);
		write(1, " ", 1);
		write(1, &num[2], 1);
		write(1, &num[3], 1);
	}
}

void	ft_loops(char *num)
{
	while (num[0] <= '9')
	{
		while (num[1] <= '9')
		{
			while (num[2] <= '9')
			{
				while (num[3] <= '9')
				{
					ft_conditions(num);
					num[3]++;
				}
				num[2]++;
				num[3] = num[1];
			}
			num[1]++;
			num[2] = num[0];
			num[3] = num[1];
		}
		num[0]++;
		num[1] = '0';
		num[2] = num[0];
		num[3] = num[1];
	}
}

void	ft_print_comb2(void)
{
	char num[4];

	num[0] = '0';
	num[1] = '0';
	num[2] = '0';
	num[3] = '1';
	ft_loops(num);
}
