/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:48:44 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/13 18:51:28 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	sights(void)
{

}

void	int_combs(void)
{
    int combs[22];
 
    combs[0] = 4123;
    combs[1] = 4213;
    combs[2] = 3124;
    combs[3] = 3214;
	combs[4] = 4132;
	combs[5] = 4231;
	combs[6] = 4312;
	combs[7] = 2134;
	combs[8] = 2314;
	combs[9] = 1324;
	combs[10] = 1432;
	combs[11] = 2431;
	combs[12] = 3421;
	combs[13] = 1243;
	combs[14] = 1342;
	combs[15] = 2341;
	combs[16] = 1423;
	combs[17] = 2143;
	combs[18] = 2413;
	combs[19] = 3142;
	combs[20] = 3241;
	combs[21] = 3412;
}

char    combs_converter_x(int *combs, int *aux, int x, int y)
{
    char digit[4];
    int comb1_2[2];
    int i;
    int exp;
    
    i = 4;
    exp = 1;
    if (xcases(y) == 1)
    {
        while (i >= 0)
        {
            digit[i] = 4321 / exp % 10 + 48;
            exp = exp * 10;
            i--;
        }
    }
    else
    {
        while (i >= 0)
        {
            digit[i] = combs[aux[2]] / exp % 10 + 48;
            exp = exp * 10;
            i--;
        }
    }
    i = 4;
    return (digit[x])
}

int main(int argc, char **argv)
{
    char parameters[16];
    
    if (xcases(y) == 0 && ycases(x) == 0)
        write(1, "Error", 5);
    else
    {
        
    }
}


