/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:43:07 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/05 13:23:53 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long int i;
	unsigned long int j;
	unsigned long int k;
	unsigned long int l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (dst[i])
		i++;
	l = i;
	while (src[k])
		k++;
	if (i >= dstsize || dstsize == 0)
		return (k + dstsize);
	while (src[j] != '\0' && dstsize > (dstsize - i - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (k + l);
}
