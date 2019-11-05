/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:17:28 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/18 10:07:06 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int n;
	int aux;
	int i;

	n = nb;
	aux = nb;
	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (aux > 1)
	{
		aux = aux - 1;
		n *= aux;
		i++;
	}
	return (n);
}
