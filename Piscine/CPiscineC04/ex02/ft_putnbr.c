/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:27:55 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/10 02:37:03 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_aux(long int *nbconvert, long int exp, int counter, char towrite)
{
	while (nbconvert[0] != 0 || nbconvert[2] == 0)
	{
		nbconvert[0] = nbconvert[0] / 10;
		exp = exp * 10;
		counter++;
		nbconvert[2]++;
	}
	if (nbconvert[1] < 0)
	{
		write(1, "-", 1);
		nbconvert[1] = nbconvert[1] * -1;
	}
	while (counter != 0)
	{
		exp = exp / 10;
		towrite = (nbconvert[1] / exp % 10) + 48;
		write(1, &towrite, 1);
		--counter;
	}
}

void	ft_putnbr(int nb)
{
	long int	nbconvert[3];
	long int	exp;
	int			counter;
	char		towrite;

	towrite = 0;
	nbconvert[0] = nb;
	nbconvert[1] = nb;
	counter = 0;
	exp = 1;
	ft_aux(nbconvert, exp, counter, towrite);
}
