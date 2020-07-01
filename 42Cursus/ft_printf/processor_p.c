/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 08:47:27 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/06/25 15:13:13 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

char	*hex_to_pointer(t_tab *tab, char *str)
{
	char *s;
	char *point;

	s = NULL;
	point = NULL;
	if (tab->flag_precision <= (int)ft_strlen(str) && tab->is_null_s != 4)
	{
		s = str;
		point = "0x";
		if (!(str = (char*)malloc(ft_strlen(s) + ft_strlen(point) + 1)))
			return (0);
		str = ft_strjoin(point, s);
		free(s);
		return (str);
	}
	tab->is_null_s = 42;
	return (str);
}

char	*p_is_null(t_tab *tab, char *str)
{
	char *null_p;

	null_p = "(nil)";
	tab->is_null_s = 4;
	free(str);
	if (!(str = (char*)malloc(6)))
		return (NULL);
	str = ft_strcpy(str, null_p);
	if (tab->flag_precision == (int)ft_strlen(str)
		&& tab->flag_width > 0)
		tab->sp_s = 3;
	return (str);
}

void	init_p(t_tab *tab, long int n, int *k, long int *nb)
{
	tab->sp_p = 1;
	nb[0] = n;
	nb[1] = nb[0];
	k[0] = 0;
	k[1] = 0;
	tab->sp_on++;
}

void	conv_p(t_tab *tab, long int *nb, int *k, char *str)
{
	int i;

	i = 0;
	while ((k[1]-- > 0 && nb[1] < 0) || nb[0] > 0)
	{
		str[k[0]++] = tab->s_base[nb[0] % 16];
		nb[0] /= 16;
	}
	while (str[i])
	{
		str[i] = (char)ft_tolower((int)str[i]);
		i++;
	}
}

char	*processor_p(t_tab *tab)
{
	char		*str;
	long int	n;
	long int	nb[2];
	int			k[2];

	n = (long)va_arg(tab->punt_arg, long int);
	init_p(tab, n, k, nb);
	if (n == '\0')
	{
		str = p_is_null(tab, str);
		return (str);
	}
	while (nb[0] > 0 || nb[1] == 0)
	{
		nb[0] /= 10;
		nb[1] -= 2;
		k[1]++;
	}
	if (!(str = (char*)ft_calloc(sizeof(k[1]), (k[1] + 1))))
		return (0);
	nb[0] = (long)n;
	conv_p(tab, nb, k, str);
	ft_strrev(str);
	str = hex_to_pointer(tab, str);
	return (str);
}
