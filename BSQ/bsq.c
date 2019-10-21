/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:40:04 by lcanales          #+#    #+#             */
/*   Updated: 2019/10/21 21:36:47 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		count_column(char *fullfile);
int		num_param(char *line_1, char *fullfile);

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
	strdict = malloc(i);
	file = open(plantilla, O_RDONLY);
	read(file, strdict, i);
	close(file);
//	free(strdict);
	return (strdict);
}

void	ft_tabletop(int x, int y, char *fullfile, char *line_1)
{
	int		i;
	int		h;
	int		j;
	char	**tabletop;

	x = count_column(fullfile);
	y = num_param(line_1, fullfile);
	i = 0;
	j = 0;
	tabletop = malloc(x * 8);
	while (i < x)
	{
		tabletop[i] = malloc(y);
		i++;
	}
	i = -1;
	h = -1;
	while (++i < y)
	{
		while (++h < x)
		{
			tabletop[i][h] = fullfile[j++];
			write(1, &tabletop[i][h], 1);
		}
		h = -1;
	}
}

int		count_column(char *fullfile)
{
	int		column;
	int		i;

	i = 0;
	column = 0;
	while (fullfile[i] != '\n')
		i++;
	while (fullfile[i + 1] != '\n')
	{
		column++;
		i++;
	}
	return (column);
}

int		num_param(char *line_1, char *fullfile)
{
	char	*num;
	int		j;
	int		row;
	int		i;

	i = 0;
	while (fullfile[i] != '\n')
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
	free(num);
	return (row);
}

void	last_params(char *fullfile)
{
	char	params[4];
//	char	*newfile;
	char	*line_1;
	int		i;
	int		j;
//	int 	k;

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
//	k = 0;
//	j += j;
//	while (fullfile[j])
//		j++;
//	newfile	= malloc(j);
//	j = 0;
	/*while (fullfile[i + ++j])
	{
		newfile[k] = fullfile[j];
		k++;
	}*/
//	printf("%s", newfile);
	line_1[j] = '\0';
	params[3] = '\0';
	params[2] = fullfile[i - 1];
	params[1] = fullfile[i - 2];
	params[0] = fullfile[i - 3];
	ft_tabletop(0, 0, fullfile, line_1);
}

int		main(int argc, char **argv)
{
	char *fullfile;

	(void)argc;
	(void)argv;
	fullfile = dict_in_str("plantilla", 0, 1);
	last_params(fullfile);
	return (0);
}
