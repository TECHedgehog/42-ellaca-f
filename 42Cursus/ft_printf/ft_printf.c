/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:08:38 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/03/02 15:14:29 by ellaca-f         ###   ########.fr       */
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
		processor(tab);
		va_end(tab->punt_arg);
	}
	free(tab);
	return (tab->len);
}

/*int main (void)
{
	//ft_printf("hola");
	// int i = 22;
	//printf("%d\n", ft_printf("%d", i));
	ft_printf("this %d number", -267);
	//printf("%d", 17);
	//printf("%d\n", printf("%05d", 23));
	return (0);
}*/
