/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:40:04 by lcanales          #+#    #+#             */
/*   Updated: 2019/10/22 18:38:41 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		count_column(char *newfile);
int		num_param(char *line_1);

/*int		arc_tester(char **tabletop, int x, int y)
{
	int flag;
	int k;
	int i;
	int j;

	j = x;
	k = 0;
	i = y;
	flag = 1;
	while (flag == 1)
	{
		while (k )
		{
			if (tabletop_num[i + k][j + k] * tabletop_num[][] == 0)
				flag = 0;
			i--;
		}
		k++;
	}
	return (0);
}*/

/*void	bsqminas(char **tabletop_num, int x, int y)
{
	int i;
	int j;
	int k;
	int h;
	int max;

	i = 0;
	j = 0;
	k = 0;
	h = 0;
	while (i < y)
	{
		while (j < x)
		{
			arc_tester(tabletop_num, j, i);
			j++;
		}
		k = 0;
		i++;
		j = 0;
	}
}*/

char	*dict_in_str(char *plantilla, int file, int b)
{
	char	*strdict;
	int		i;
	char	str[1];

	i = 0;
	file = open(plantilla, O_RDONLY);
	while (b != 0)
	{
		b = read(file, str, 1);
		i++;
	}
	close(file);
	strdict = malloc(i + 1);
	if (strdict == 0)
		return (0);
	file = open(plantilla, O_RDONLY);
	read(file, strdict, i);
	strdict[i] = '\0';
	close(file);
	return (strdict);
}

char	**ft_tabletop(int y, char *newfile, char *line_1, char *params)
{
	int		i;
	int		h;
	int		j;
	int		x;
	int		**tabletop_num;
	char	**tabletop;

	x = count_column(newfile) + 1;
	y = num_param(line_1);
	i = 0;
	j = 0;
	tabletop_num = malloc(x - 1 * 8);
	tabletop = malloc(x * 8);
	while (i < x)
	{
		tabletop_num[i] = malloc(y);
		tabletop[i] = malloc(y);
		i++;
	}
	i = -1;
	h = -1;
	while (++i < y)
	{
		while (++h < x)
		{
			if (newfile[j] == params[1])
				tabletop_num[i][h] = 0;
			else
				tabletop_num[i][h] = 1;
			tabletop[i][h] = newfile[j];
			j++;
			//write(1, &tabletop[i][h], 1);
			printf("%i", tabletop_num[i][h]);
		}
		printf("\n");
		h = -1;
	}
			printf("%c\n", params[1]);
	return (tabletop);
}

int		count_column(char *newfile)
{
	int		column;
	int		i;

	i = 0;
	column = 0;
	while (newfile[i] != '\n')
	{
		column++;
		i++;
	}
	return (column);
}

int		num_param(char *line_1)
{
	char	*num;
	int		j;
	int		row;
	int		i;

	i = 0;
	while (line_1[i])
		i++;
	row = 0;
	j = -1;
	num = malloc(i - 3);
	while (++j < i - 3)
		num[j] = line_1[j];
	num[j] = '\0';
	j = -1;
	while (num[++j])
	{
		row *= 10;
		row += num[j] - 48;
	}
	//free(num);
	return (row);
}

void	last_params(int i, int j, int k, char *fullfile)
{
	char	params[4];
	char	*newfile;
	char	*line_1;
	int		c[2];

	i = 0;
	while (fullfile[i] != '\n')
		i++;
	line_1 = malloc(i);
	j = 0;
	while (fullfile[j] != '\n')
	{
		line_1[j] = fullfile[j];
		j++;
	}
	line_1[j] = '\0';
	k = 0;
	j += 1;
	while (fullfile[j])
		j++;
	newfile = malloc(j);
	j = 0;
	while (fullfile[++j + i])
		newfile[k++] = fullfile[j + i];
	c[0] = count_column(newfile) + 1;
	c[1] = num_param(line_1);
	params[3] = '\0';
	params[2] = fullfile[i - 1];
	params[1] = fullfile[i - 2];
	params[0] = fullfile[i - 3];
	ft_tabletop(0, newfile, line_1, params);
	//free (line_1);
	//free (newfile);
	//bsqminas(ft_tabletop(0, newfile, line_1, params), c[0], c[1], params);
}

int		main(int argc, char **argv)
{
	char *fullfile;

	(void)argc;
	(void)argv;
	fullfile = dict_in_str("plantilla", 0, 1);
	last_params(0, 0, 0, fullfile);
	return (0);
}
