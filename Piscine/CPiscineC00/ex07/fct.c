/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:28:19 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/09 18:53:34 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
int main()
{
	int nb;
	
	nb = 0;
	ft_putnbr(nb);
	write(1,"\n", 1);
	nb = 51535151;
	ft_putnbr(nb);
	write(1,"\n", 1);
	nb = 2147483647;
	ft_putnbr(nb);
	write(1,"\n", 1);
	nb = -2147483648;
	ft_putnbr(nb);
	return (0);
}