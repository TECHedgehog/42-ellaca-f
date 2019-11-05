/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:18:23 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/05 12:42:34 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long int i;
	unsigned long int j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	while (j < dstsize)
	{
		if (j < (dstsize - 1))
			dst[j] = src[j];
		else
			dst[j] = '\0';
		j++;
	}
	return (i);
}
