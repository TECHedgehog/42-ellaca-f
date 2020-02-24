/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:28:17 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/02/24 20:53:00 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

char	*processor_di(t_tab *tab)
{
	char		*str;
	int			n;
	long int	nb[2];
	long int	exp;

	exp = 1;
	n = va_arg(tab->punt_arg, int);
	nb[0] = (n < 0) ? (long)n * -1 : (long)n;
	nb[1] = (long)nb[0];
	while (nb[0] > 0 || nb[1] == 0)
	{
		nb[0] /= 10;
		exp *= 10;
		nb[1] += 2;
		tab->j++;
	}
	if (n < 0)
	{
		if (!(str = (char*)malloc(sizeof(tab->j + 2))))
			return (0);
		str[tab->j + 1] = '\0';
		tab->j = 0;
		str[tab->j++] = '-';
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(tab->j + 1))))
			return (0);
		str[tab->j] = '\0';
	}
	nb[0] = (n < 0) ? (long)n * -1 : (long)n;
	exp /= 10;
	while (exp > 0)
	{
		str[tab->j] = nb[0] / exp % 10 + 48;
		exp /= 10;
		tab->j++;
	}
	return (str);
}
