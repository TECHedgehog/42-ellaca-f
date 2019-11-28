/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:22:50 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/28 16:59:42 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <fcntl.h>

void	get_next_line(int fd, char **line)
{
	char	*firstline;
	int		i;

	i = 0;
	read(fd, firstline, BUFFER_SIZE);
	while (firstline[i] != '\n')
	{
		*line[i] = firstline[i];
		i++;
	}
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
	char 	**line;

	get_next_line(open("prueba.txt", O_RDONLY), line);
	//lab_get_next_line();
}
