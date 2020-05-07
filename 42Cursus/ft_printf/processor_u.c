/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 12:53:14 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/05/07 13:08:49 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void    init_u(t_tab *tab, int n, unsigned int *nb)
{
    tab->sp_on++;
    tab->sp_u = 1;
    nb[0] = n;
    nb[1] = n;
}

void    conv_u(char *str, unsigned int *nb, long int exp)
{
    int i;

    i = 0;
    while (exp > 0)
    {
        str[i] = nb[0] / exp % 10 + 48;
        exp /= 10;
        i++;
    }
}

char    *processor_u(t_tab *tab)
{
    char                *str;
    int                 k;
    unsigned int   n;
    unsigned int   nb[2];
    long int            exp;

    exp = 1;
	k = 0;
	n = (unsigned)va_arg(tab->punt_arg, unsigned int);
	init_u(tab, n, nb);
	while (nb[0] > 0 || nb[1] == 0)
	{
		nb[0] /= 10;
		exp *= 10;
		nb[1] += 2;
		k++;
	}
	if (!(str = (char*)malloc(sizeof(k + 1))))
		return (0);
	str[k] = '\0';
	nb[0] = (n < 0) ? (long)n * -1 : (long)n;
	exp /= 10;
	conv_u(str, nb, exp);
	return (str);
}