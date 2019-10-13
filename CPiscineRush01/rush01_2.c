/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:08:19 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/13 18:51:55 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int xcases(int y)
{
    int r_l[4];
    int r_r[4];
    
    if (r_l[y] == 1 && r_r[y] == 4)
        return (1);
    else if (r_l[y] == 4 && r_r[y] == 1)
        return (2);
    else if (r_l[y] == 1 && r_r[y] == 2)
        return (3);
    else if (r_l[y] == 2 && r_r[y] == 1)
        return (4);
    else if (r_l[y] == 1 && r_r[y] == 3)
        return (5);
    else if (r_l[y] == 3 && r_r[y] == 1)
        return (6);
    else if (r_l[y] == 2 && r_r[y] == 3)
        return (7);
    else if (r_l[y] == 3 && r_r[y] == 2)
        return (8);
    else if (r_l[y] == 2 && r_r[y] == 2)
        return (9);
    return (0);
}

int ycases(int x)
{
    int c_u[4];
    int c_d[4];
    
    if (c_u[x] == 1 && c_d[x] == 4)
        return (1);
    else if (c_u[x] == 4 && c_d[x] == 1)
        return (2);
    else if (c_u[x] == 1 && c_d[x] == 2)
        return (3);
    else if (c_u[x] == 2 && c_d[x] == 1)
        return (4);
    else if (c_u[x] == 1 && c_d[x] == 3)
        return (5);
    else if (c_u[x] == 3 && c_d[x] == 1)
        return (6);
    else if (c_u[x] == 2 && c_d[x] == 3)
        return (7);
    else if (c_u[x] == 3 && c_d[x] == 2)
        return (8);
    else if (c_u[x] == 2 && c_d[x] == 2)
        return (9);
    return (0);
}

void	tabletop_comb(void)
{
	char tabletop1[4] [4];
	char tabletop2[4] [4];
	int x;
	int y;
	int power;
	int aux[3];

	x = 0;
	y = 0;
	aux[0] = 0;
	aux[1] = 0;
	aux[2] = 0;
	while (y <= 3)
	{
		while (x <= 3)
		{
			tabletop1[y] [x] = '\0';
			tabletop2[y] [x] = '\0';
			x++;
		}
		y++;
	}
	x = 0;
	y = 0;
	power = 1;
	while (power != 0)
	{
		while (y < 4)
		{
			if (xcases(y) == 1 || xcases(y) == 2)
			{
				while (x < 4)
				{
					tabletop1[y] [x] = ;
					x++;
				}
			}
            y++;
			x = 0;
		}
		aux[0] = 0;
		x = 0;
		y = 0;
		while (y < 4)	//tablero x
		{
			while(x < 4)
			{
				if (xcases(y) != 1 || xcases(y) != 2)
				{
					if (tabletop1[0] [x] !=  &&
						tabletop1[1] [x] !=  &&
						tabletop1[2] [x] !=  &&
						tabletop1[3] [x] != )
					{
						tabletop1[y] [x] = ;
						x++;
					}
					else
					{
						aux[1]++;
						x = 0;
					}
				}
                y++;
			}
			aux[1] = 0;
			aux[0]++;
			x = 0;
			y = 0;
			while (x < 4)	//tablero y dentro de tablero x
			{
				while(y < 4)
				{
                    x = aux[0];
					if (ycases[aux[0]] != 1 && ycases[aux[0]] != 2)
					{
						if (tabletop2[0] [x] != &&
							tabletop2[1] [x] != &&
							tabletop2[2] [x] != &&
							tabletop2[3] [x] != &&
							tabletop1[y] [0] != &&
							tabletop1[y] [1] != &&
							tabletop1[y] [2] != &&
							tabletop1[y] [3] != )
						{
							tabletop2[y] [x] = ;
							y++;
						}
						else if (aux[1] < 6)
						{
							aux[1]++;
							y = 0;
						}
                        else
                        {
                            write(1, "Error", 5);
                            break ;
                        }
					}
				}
				aux[0]++;
				y = 0;
			}
			x = 0;
			y = 0;
			aux[0] = 0;
		}
		x = 0;
		y = 0;
		while (y < 4)
		{
			while (x < 4)
			{	
				if (tabletop1[x] [y] == tabletop2[x] [y])
				aux[0]++;
				x++;
			}
			y++;
			x = 0;
		}
        x = 0;
        y = 0;
        while (y < 4)
        {
            while (x < 4)
            {
                write(1, &tabletop1[x] [y], 1);
                x++;
            }
            y++;
            power = 0;
        }
	}
}




/*void	combs_casos1(void)
{
	int caso1;
	int caso2;
	int caso3[2];
	int caso4[2];
	
	caso1 = 4321;
	caso2 = 1234;
	caso3[0] = 4123;
	caso3[1] = 4213;
	caso4[0] = 3124;
	caso4[1] = 3214;
}

void	comb_casos2(void)
{
	int caso5[3];
	int caso6[3];
	int caso7[3];
	int caso8[3];
	int caso9[6];

	caso5[0] = 4132;
	caso5[1] = 4231;
	caso5[2] = 4312;
	caso6[0] = 2134;
	caso6[1] = 2314;
	caso6[2] = 1324;
	caso7[0] = 1432;
	caso7[1] = 2431;
	caso7[2] = 3421;
	caso8[0] = 1243;
	caso8[1] = 1342;
	caso8[2] = 2341;
	caso9[0] = 1423;
	caso9[1] = 2143;
	caso9[2] = 2413;
	caso9[3] = 3142;
	caso9[4] = 3241;
	caso9[5] = 3412;
}*/
