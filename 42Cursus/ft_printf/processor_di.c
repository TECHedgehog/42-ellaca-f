/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:28:17 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/04/23 23:01:00 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void	init(t_tab *tab, int n, long int *nb)
{
	tab->is_negative = (n < 0) ? 1 : 0;
	nb[0] = (n < 0) ? (long)n * -1 : (long)n;
	nb[1] = (long)nb[0];
}

void	conv(char *str, long int *nb, long int exp, t_tab *tab)
{
	int i;

	i = 0;
	while (exp > 0)
	{
		str[i] = nb[0] / exp % 10 + 48;
		exp /= 10;
		i++;
	}
	tab->sp_di = 1;
}

char	*processor_di(t_tab *tab)
{
	char		*str;
	int			n;
	int			k;
	long int	nb[2];
	long int	exp;

	exp = 1;
	k = 0;
	n = va_arg(tab->punt_arg, int);
	init(tab, n, nb);
	while (nb[0] > 0 || nb[1] == 0)
	{
		nb[0] /= 10;
		exp *= 10;
		nb[1] += 2;
		k++;
	}
	tab->j = k;
	if (!(str = (char*)malloc(sizeof(k + 1))))
		return (0);
	str[k] = '\0';
	nb[0] = (n < 0) ? (long)n * -1 : (long)n;
	exp /= 10;
	conv(str, nb, exp, tab);
	return (str);
}
