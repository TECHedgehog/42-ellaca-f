/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:28:17 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/04/08 11:38:32 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

/*int		processor_di_malloc(t_tab *tab, char *str, int n)
{
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
	return (1);
}*/

/*void	processor_di_init(t_tab *tab, long int *nb, long int exp)
{
	while (nb[0] > 0 || nb[1] == 0)
	{
		nb[0] /= 10;
		exp *= 10;
		nb[1] += 2;
		tab->j++;
	}
}*/

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
	nb[0] = (n < 0) ? (long)n * -1 : (long)n;
	nb[1] = (long)nb[0];
	while (nb[0] > 0 || nb[1] == 0)
	{
		nb[0] /= 10;
		exp *= 10;
		nb[1] += 2;
		k++;
	}
	tab->j = k;
	// if (!(processor_di_malloc(tab, str, n)))
		// return (0);
	if (n < 0)
	{
		if (!(str = (char*)malloc(sizeof(k + 2))))
			return (0);
		str[k + 1] = '\0';
		k = 0;
		str[k] = '-';
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(k + 1))))
			return (0);
		str[k] = '\0';
	}
	nb[0] = (n < 0) ? (long)n * -1 : (long)n;
	exp /= 10;
	k = (n < 0) ? 1 : 0;
	while (exp > 0)
	{
		str[k] = nb[0] / exp % 10 + 48;
		exp /= 10;
		k++;
	}
	return (str);
}
