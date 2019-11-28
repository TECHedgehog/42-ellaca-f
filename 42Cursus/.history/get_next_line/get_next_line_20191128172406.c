/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:22:50 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/28 17:24:06 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

void	get_next_line(char **line)
{
	char	saved[BUFFER_SIZE];
	char	*oneline;
	int		i;
	int		fildes;
	
	fildes = open("prueba.txt", O_RDWR);
	i = 0;
	read(fildes, saved, BUFFER_SIZE);
	close(fildes);
		printf("KK");
	while (saved[i] != '\n')
	{
		oneline[i] = saved[i];
		i++;
	}
	*line = oneline;
}

/*void lab_get_next_line(void)
{
	int		i;
	int		fildes;
	char	firstline[16];

	fildes = open("prueba.txt", O_RDWR);
	i = 0;
	read(fildes, firstline, BUFFER_SIZE);
	close(fildes);
	printf("%s\n", firstline);
}*/

int main()
{
	char	**line;
	//int		fildes = open("prueba.txt", O_RDWR);

	get_next_line(line);
	//close(fildes);
	printf("%s\n", *line);
	//lab_get_next_line();
}
