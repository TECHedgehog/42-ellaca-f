/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 08:47:27 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/09/08 19:47:15 by ellaca-f         ###   ########.fr       */
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

	null_p = "0x0";
	tab->is_null_s = 3;
	free(str);
	if (!(str = (char*)malloc(4)))
		return (NULL);
	str = ft_strcpy(str, null_p);
	if (tab->flag_precision == (int)ft_strlen(str)
		&& tab->flag_width > 0)
		tab->sp_s = 3;
	return (str);
}

void	init_p(t_tab *tab, unsigned long int n, int *k, long int *nb)
{
	tab->sp_p = 1;
	nb[0] = (long)n;
	nb[1] = nb[0];
	k[0] = 0;
	k[1] = 0;
	tab->sp_on++;
}

void	conv_p(t_tab *tab, long int *nb, int *k, char *str)
{
	int i;

	i = 0;
	k[1] = (nb[0] > 9 && nb[0] < 16) ? 1 : k[1];
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
	ft_strrev(str);
}

char	*processor_p(t_tab *tab)
{
	char				*str;
	unsigned long int	n;
	long int			nb[2];
	int					k[2];

	n = va_arg(tab->punt_arg, unsigned long int);
	init_p(tab, n, k, nb);
	str = NULL;
	if (n == '\0')
	{
		str = p_is_null(tab, str);
		return (str);
	}
	while (nb[0] > 0 || nb[1] == 0)
	{
		nb[0] /= 10;
		nb[1] -= 10;
		k[1]++;
	}
	if (!(str = (char*)ft_calloc(sizeof(char), (k[1] + 1))))
		return (0);
	nb[0] = (long)n;
	conv_p(tab, nb, k, str);
	str = hex_to_pointer(tab, str);
	return (str);
}
