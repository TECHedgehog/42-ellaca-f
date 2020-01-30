/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_trasteando.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:45:46 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/01/30 14:34:20 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *formats, ...)
{
	int	i;

	i = 0;
	while (formats[i])
	{
		if (formats[i] == '%' && formats[i - 1] != '\\')
		{
			i++;
			if (formats[i] == 'c')
			{
				write(1, "OK", 2);
			}
			i++;
		}
		write(1, &formats[i], 1);
		i++;
	}
	return (0);
}

int		main(void)
{
	ft_printf("%cHOLA", (int)32);
	return (0);
}
