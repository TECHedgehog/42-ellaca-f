/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:08:38 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/02/20 18:47:58 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int		ft_printf(const char *formats, ...)
{
	t_tab *tab;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->formats = formats;
	tab = tab_initializer(tab);
	if (formats)
	{
		va_start(tab->punt_arg, formats);
		tab->len = processor(tab);
		va_end(tab->punt_arg);
	}
	free(tab);
	return (tab->len);
}

int main (void)
{
	//ft_printf("hola");
	printf("%d\n", ft_printf("hola que "));
	//printf("\n");
	//printf("%d\n", printf("%05d", 23));
	return (0);
}
