/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:08:38 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/02/25 00:32:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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
		processor(tab);
		va_end(tab->punt_arg);
	}
	free(tab);
	return (tab->len);
}

int main (void)
{
	//ft_printf("hola");
	int i = 123;
	printf("%d\n", ft_printf("%d", i));
	//printf("\n");
	//printf("%d\n", printf("%05d", 23));
	return (0);
}
