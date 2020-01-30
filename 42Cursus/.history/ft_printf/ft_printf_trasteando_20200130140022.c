/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_trasteando.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:45:46 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/01/30 14:00:22 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *formats)
{
	int		i;
	char	c;

	i = 0;
	while (formats[i])
	{
		c = (char)formats[i];
		write(1, c, 1);
		i++;
	}
	return (0);
}

int		main(void)
{
	ft_printf("HOLA");
	return (0);
}
