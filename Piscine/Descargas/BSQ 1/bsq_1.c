/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:55:23 by lcanales          #+#    #+#             */
/*   Updated: 2019/10/22 10:03:38 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*dict_in_str(char *plantilla, int file, int b)
{
	char *strdict;
	int i;
	char str[1];
	
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
	free(strdict);
	return (strdict);
}
int		count_column(char *fullfile, int i)
{
	int column;
	column = 0;
	while (fullfile[i + 1] != '\n')
	{
		column++;
		i++;
	}
	return (column);
}

int		 count_row(char *line_1, int i)
{
	char 	*num;
	int		j;
	int 	row;
	
	row = 0;
	j = 0;
	num = malloc(i - 3);
	while (j < i - 3)
	{
 		 num[j] = line_1[j];
 		 j++;
 	}
	num[j] = '\0';
	free(num);
	j = 0;
	while (num[j])
	{
		row *= 10;
		row += num[j] - 48;
		j++;
	}
	return (row);
}

void	fill_tabletop(char **tabletop, char *fullfile)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (fullfile[i] != '\n')
		i++;
	while (fullfile[++i] != '\0')
	{
		*tabletop[j] = fullfile[i];
		j++;
	}
	*tabletop[j] = '\0';
}

void	ft_tabletop(int x, int y, char *fullfile)
{
	char	**tabletop;
	int		i;

	i = 0;
	tabletop = malloc(x * 8);
	while (i < x)
	{
		tabletop[i] = malloc(y);
		i++;
	}
	fill_tabletop(tabletop, fullfile);
}

void	 find_y(char *fullfile, char **tabletop)
{
	int i;
	char characters[4];
	char *line_1;
	int j;
	int *p_row;
	int *p_column;

//	*p_row = count_row(line_1, i);
//	*p_column = count_column(fullfile, i);
	fullfile = dict_in_str("plantilla", 0, 1);
	i = 0;
	while (fullfile[i] != '\n')
		i++;
//	ft_tabletop(*p_row, *p_column, fullfile);
//	printf("%s\n", *tabletop);
//	printf("%s\n", *fill_tabletop(ft_tabletop(*p_row, *p_column), fullfile));
//	printf("%s\n", **tabletop);
	line_1 = malloc(i);
	j = 0;
	while (fullfile[j] != '\n')
	{	
		line_1[j] = fullfile[j];
		j++;
	}
	line_1[j] = '\0';
	::p_row = count_row(line_1, i);
	*p_column = count_column(fullfile, i);
	ft_tabletop(*p_row, *p_column, fullfile);
	printf("%s\n", *tabletop);
	free(line_1);
	characters[3] = '\0';
	characters[2] = fullfile[i- 1];
	characters[1] = fullfile[i - 2];
	characters[0] = fullfile[i - 3];
	
}

int		main(int argc, char ** argv)
{
	(void)argc;
	(void)argv;
	char *fullfile;
	char	**tabletop;
	fullfile = dict_in_str("plantilla", 0, 1);
	find_y(fullfile, tabletop);
	return (0);
}







