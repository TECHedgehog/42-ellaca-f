/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:49:09 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/23 23:32:48 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	while (j < size)
	{
		if (j < (size - 1))
			*(dest + j) = *(src + j);
		else
			*(dest + j) = '\0';
		j++;
	}
	return (i);
}
