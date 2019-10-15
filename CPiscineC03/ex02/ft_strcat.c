/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 04:47:56 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/15 08:53:04 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	while (dest[i])
	{
		src[j] = dest[i];
		j++;
		i++;
	}
	src[j] = '\0';
	return (src);
}
