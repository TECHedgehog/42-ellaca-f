/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:21:01 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/19 11:18:44 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str1;
	const unsigned char *str2;
	int					i;

	i = 0;
	str1 = dst;
	str2 = src;
	while (n > 0)
	{
		if (n > 0 && str1 == NULL && str2 == NULL)
			return (dst);
		str1[i] = str2[i];
		i++;
		n--;
	}
	return (dst);
}
