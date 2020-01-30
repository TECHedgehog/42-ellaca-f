/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_trasteando.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:45:46 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/01/30 17:34:00 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int		ft_printf(const char *formats, ...)
{
	int	i;
	t_tab tab;

	i = 0;
	va_start(tab.punt_arg, formats);
	while (formats[i])
	{
		if (formats[i] == '%' && formats[i - 1] != '\\')
		{
			i++;
			if (formats[i] == 'c')
			{

				write(1, va_arg(tab.punt_arg, int), 2);
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
