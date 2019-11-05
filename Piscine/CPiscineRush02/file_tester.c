/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:16:31 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/20 23:45:45 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	byte_counter(void)
{
	char	trash[1];
	int		count;
	int		fildes;

	count = 0;
	fildes = open("Dict.txt", O_RDONLY);
	if (fildes >= 0)
	{
		fildes = open("Dict.txt", O_RDWR);
		while (read(fildes, trash, 1) > 0)
		{
			count++;
		}
	}
	return (count);
}

char	*strstr_dout(char *copy_dict, char *to_find, int i, int j)
{
	while (copy_dict[i] != 0)
	{
		j = 0;
		if (copy_dict[i] == to_find[j] && copy_dict[i - 1] == '\n')
		{
			while (copy_dict[i + j] == to_find[j] && to_find[j] != '\0')
				i++;
				j++;
			if (to_find[j] == '\0')
			{
				while (copy_dict[i] != '\0')
				{
					if (copy_dict[i] == ':')
						return (&copy_dict[i + 1]);
					i++;
				}
			}
			i -= j;
		}
		i++;
	}
	return (0);
}

int get_dout(char *copy_dict, char *to_find)
{
	unsigned int i;
	unsigned int j;
	int size;

	i = 0;
	j = 0;
	while (to_find[j++])
	size = j;
	j = 0;
	if (strstr_dout(copy_dict, to_find, i, j) + i != 0)
	{
		while (*(strstr_dout(copy_dict, to_find, i, j) + i) != '\n')
		{
			if (*(strstr_dout(copy_dict, to_find, i, j) + i) == ' ' || 
				*(strstr_dout(copy_dict, to_find, i, j) + i) == '\t' ||
				*(strstr_dout(copy_dict, to_find, i, j) + i) == '\r' || 
				*(strstr_dout(copy_dict, to_find, i, j) + i) == '\v' ||
				*(strstr_dout(copy_dict, to_find, i, j) + i) == '\f')
				i++;
			else
			{
				write(1, (strstr_dout(copy_dict, to_find, i, j) + i), 1);
				i++;
			}
		}
		return (0);
	}
	return(1);
}

void	dict_strcpy(char *origin_dict, char *copy_dict, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j <= size)
	{
		if (origin_dict[i] == ' ' || origin_dict[i] == '\t' || origin_dict[i] == '\r' ||
			origin_dict[i] == '\v' || origin_dict[i] == '\f')
			i++;
		else if (origin_dict[i] == '\0' && i < size)
		{
			while (j < size)
			{
				copy_dict[j] = '\0';
				j++;
			}
		}
		else
		{
			copy_dict[j] = origin_dict[i];
			i++;
			j++;
		}
	}
	copy_dict[i] = '\0';
}

