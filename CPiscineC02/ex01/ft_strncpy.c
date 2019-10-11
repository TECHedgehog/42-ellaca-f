/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 04:25:59 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/10 06:03:03 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (*(src + i) != 0)
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
