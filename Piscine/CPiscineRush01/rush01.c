/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:58:12 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/12 17:52:05 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	//char *tabletop = malloc(sizeof(char[4] [4]));
	char sights[16];
	char 
	int x;
	int y;
	(void) argc;
	(void) argv;
	
	x = 0;
	y = 0;
	sights[0] = ;

}

void	three_comb(void)
{
	int three_comb[4];

	three_comb[0] = 1243;
	three_comb[1] = 1342;
	three_comb[2] = 2341;
	three_comb[3] = 2134;
}

void	two_comb(void)
{
	while ()
	{
		
	}
}

void	skyscrapper(char sights, char *tabletop)
{
	int aux[4];
	int x;
	int y;

	x = 0;
	y = 0;
	aux[0] = 0;
	aux[1] = 0;
	aux[2] = 0;
	aux[3] = 1;
	while (aux[0] <= 16)
	{
		if (sights[aux[0]] == '4')
		{
			if (aux[0] <= 4)
			{
				x = aux[0];
				while (y <= 3)
				{
					tabletop[x] [y] = aux[3];
					aux[3] = aux[3] + 1;
					y++;
				}
			}
			else if (aux[0] >= '5' && aux[0] <= '8')
			{
				x = aux[0] - 4;
				y = 3;
				while (y >= 0)
				{
					tabletop[x] [y] = aux[3];
					aux[3] = aux[3] - 1;
					y--;
				}
			}
			else if (aux[0] >= '9' && aux[0] <= '12')
			{
				while (x <= 0)
				{

				}	
			}
			else if (aux[0] >= '13' && aux[0] <= '16')

		}
		aux[0]++;
		aux[3] = 4;
		x = 0;
		y = 0;
	}
}
