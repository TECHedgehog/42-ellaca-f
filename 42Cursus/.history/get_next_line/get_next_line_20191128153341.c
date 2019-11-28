/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:22:50 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/28 15:33:41 by ellaca-f         ###   ########.fr       */
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
	char	trash[1];
	char	*firstline;

	fildes = open("prueba.txt", O_RDWR);
	i = 0;
	while (i < 15)
	{
		read(fildes, trash, 1);
		firstline[i] = trash[0];
		i++;
	}
	close(fildes);
	printf("%s\n", firstline);
}

int main()
{
	lab_get_next_line();
}
