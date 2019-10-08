/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:06:44 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/06 21:29:27 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int *p_currntx, int *p_currnty, int *p_endx, int *p_endy);

void	looprush(int y, int *p_endx, int *p_endy);

void	rush(int x, int y)
{
	int *p_endx;
	int *p_endy;

	p_endx = &x;
	p_endy = &y;
	looprush(y, p_endx, p_endy);
}

void	looprush(int y, int *p_endx, int *p_endy)
{
	int currntx;
	int currnty;
	int *p_currntx;
	int *p_currnty;

	currntx = 1;
	currnty = 1;
	p_currntx = &currntx;
	p_currnty = &currnty;
	while (currnty <= y)
	{
		ft_putchar(p_currntx, p_currnty, p_endx, p_endy);
		currntx = 1;
		currnty++;
	}
}
