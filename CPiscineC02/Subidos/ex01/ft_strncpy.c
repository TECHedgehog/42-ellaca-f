/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 04:25:59 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/11 12:32:49 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (*(src + i) != '\0')
	{
		while (i <= n)
		{
			*(dest + i) = *(src + i);
			i++;
		}
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
