/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:25:55 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/05 10:59:59 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*str1;
	const unsigned char *str2;
	int					i;

	i = 0;
	str1 = dst;
	str2 = src;
	while (len > 0)
	{
		if (str2 == str1)
			break ;
		str1[i] = *str2;
		i++;
		str2++;
		len--;
	}
	return (dst);
}
