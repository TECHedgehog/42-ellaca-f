/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:18:23 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/21 20:39:31 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long int i;
	unsigned long int j;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	j = 0;
	while (src[i])
		i++;
	while (j < dstsize && j <= i)
	{
		if (j < (dstsize - 1))
			dst[j] = src[j];
		else
			dst[j] = '\0';
		j++;
	}
	return (i);
}
