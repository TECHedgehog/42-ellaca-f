/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 08:47:27 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/05/07 13:21:07 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void	init_x(t_tab *tab, long int n, int *k, long int *nb)
{
	tab->is_negative = (n < 0) ? 1 : 0;
	nb[0] = (n < 0) ? (long)n * -1 : (long)n;
	nb[1] = (long)nb[0];
	k[0] = 0;
	k[1] = 0;
	tab->sp_on++;
}

void	conv_x(t_tab *tab, long int *nb, int *k, char *str)
{
	int i;

	i = 0;
	while ((k[1]-- > 0 && nb[1] < 0) || nb[0] > 0)
	{
		str[k[0]++] = tab->s_base[nb[0] % 16];
		nb[0] /= 16;
	}
	if (tab->formats[tab->i] == 'x')
	{
		while (str[i])
		{
			str[i] = (char)ft_tolower((int)str[i]);
			i++;
		}
	}
}

char	*processor_x(t_tab *tab)
{
	char		*str;
	long int	n;
	int			k[2];
	long int	nb[2];

	n = va_arg(tab->punt_arg, long int);
	tab->is_negative = (n < 0) ? 1 : 0;
	init_x(tab, n, k, nb);
	while (nb[0] > 0 || nb[1] == 0)
	{
		nb[0] /= 10;
		nb[1] -= 2;
		k[1]++;
	}
	if (!(str = (char*)ft_calloc(sizeof(k[1]), (k[1] + 1))))
		return (0);
	nb[0] = (n < 0) ? (long)n * -1 : (long)n;
	conv_x(tab, nb, k, str);
	ft_strrev(str);
	tab->sp_x = 1;
	return (str);
}
