/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:54:27 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/28 14:35:38 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	long int	nb2;
	long int	exp;
	char		c;

	exp = 1;
	c = 0;
	nb = (n < 0) ? (long)n * -1 : (long)n;
	nb2 = (long)n;
	while (nb > 0 || nb2 == 0)
	{
		nb /= 10;
		exp *= 10;
		nb2 += 2;
	}
	if (n < 0)
		write(fd, "-", 1);
	nb = (n < 0) ? (long)n * -1 : (long)n;
	exp /= 10;
	while (exp > 0)
	{
		c = nb / exp % 10 + 48;
		exp /= 10;
		write(fd, &c, 1);
	}
}

int main ()
{
	ft_putnbr_fd(-1, 1);
}
