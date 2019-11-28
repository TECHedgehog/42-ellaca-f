/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:22:50 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/28 16:25:07 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
/*int	get_next_line(int fd, char **line)
{
	int		i;
	char	*firstline;

	i = 0;
	while (firstline[i] != '\n')
	{
		read(fd, firstline, 1);
		i++;
	}
}*/

void lab_get_next_line(void)
{
	int		i;
	int		fildes;
	char	firstline[15];

	fildes = open("prueba.txt", O_RDWR);
	i = 0;
	read(fildes, firstline, BUFFER_SIZE);
	close(fildes);
	printf("%s\n", firstline);
}

int main()
{
	lab_get_next_line();
}
