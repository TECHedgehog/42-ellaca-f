/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:05:42 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/20 23:45:43 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "prots.h"

int	byte_counter();

char	*strstr_dout(char *copy_dict, char *to_find, int i, int j);

void	dict_strcpy(char *origin_dict, char *copy_dict, int size);

int	main(int argc, char **argv)
{
	int		fildes;
	int		size = 0;
	char	*origin_dict = malloc(size);
	char	*copy_dict = malloc(size);



	if (argc == 2)
	{

	}
	else if (argc == 3)
		
	size = byte_counter();

	fildes = open("Dict.txt", O_RDONLY);
	if (fildes < 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	else
	{
		read(fildes, origin_dict, size);
		free (origin_dict);
		dict_strcpy(origin_dict, copy_dict, size);
		free (copy_dict);
	}
}
