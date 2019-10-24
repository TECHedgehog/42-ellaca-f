/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:48:41 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/24 02:33:50 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int a;
	int sqrt;

	a = 0;
	if (nb < 0)
		return (0);
	while (a < 46341)
	{
		sqrt = a * a;
		if (sqrt == nb)
			return (a);
		a++;
	}
	return (0);
}
