/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:48:45 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/07 12:54:08 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc(count * size);
	if (s != 0)
	{
		while (i < count * size)
		{
			s[i] = 0;
			i++;
		}
		return (s);
	}
	return (0);
}
