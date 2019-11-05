/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:03:41 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/05 11:01:17 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*str1;
	const unsigned char *str2;
	int					i;

	i = 0;
	str1 = dst;
	str2 = src;
	while (n > 0)
	{
		str1[i] = str2[i];
		if (str2[i] == c)
			return (&dst[i + 1]);
		i++;
		n--;
	}
	return (0);
}
