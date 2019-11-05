/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:17:00 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/06 20:58:22 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int *p_currntx, int *p_currnty, int *p_endx, int *p_endy)
{
	char startl;
	char midl;
	char endl;

	startl = 'A';
	midl = 'B';
	endl = 'C';
	while ((*p_currnty != 1 && *p_currnty != *p_endy) && *p_currntx < *p_endx)
	{
		write(1, &midl, 1);
		*p_currntx = *p_currntx + 1;
		while (*p_currntx < *p_endx)
		{
			write(1, " ", 1);
			*p_currntx = *p_currntx + 1;
		}
		write(1, &midl, 1);
		write(1, "\n", 1);
	}
	while ((*p_currnty == 1 || *p_currnty <= *p_endy) && *p_currntx < *p_endx)
	{
		write(1, &startl, 1);
		*p_currntx = *p_currntx + 1;
		while (*p_currntx < *p_endx)
		{
			write(1, &midl, 1);
			*p_currntx = *p_currntx + 1;
		}
		write(1, &endl, 1);
		write(1, "\n", 1);
	}
}
