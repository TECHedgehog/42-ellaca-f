/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:00:30 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/06 19:33:01 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*void	ft_num(char *num, int i, int j)
{
	write(1, &num[0], 1);
	write(1, &num[1], 1);
	write(1, " ", 1);
	write(1, &num[2], 1);
	write(1, &num[3], 1);
	if (num[i] == '9' && num[j] == '9')
	{
		i = i - 2;
		j = j - 2;
		write(1, &num[0], 1);
		write(1, &num[1], 1);
	}
	if (num[0] == '9' && num[1] == '8')
	{
		write(1, "\n", 1);
		num[0] = num[0] + 2;
	}
	else write(1, ", ", 2);
}*/

void	ft_print_comb2(void)
{
	char	num[4];
	int		i;
	int		j;

	i = 2;
	j = 3;
	num[0] = '0';
	num[1] = '0';
	num[2] = '0';
	num[3] = '0';
	while (num[i] <= '9')
	{
		while (num[j] <= '9')
		{
				write(1, &num[0], 1);
	write(1, &num[1], 1);
	write(1, " ", 1);
	write(1, &num[2], 1);
	write(1, &num[3], 1);
	if (num[i] == '9' && num[j] == '9')
	{
		i = i - 2;
		j = j - 2;

	}
	if (num[0] == '9' && num[1] == '8')
	{
		write(1, "\n", 1);
		break;;
	}
	write(1, ", ", 2);

			num[j]++;
		}
		num[i]++;
		num[j] = '0';
	}
}
