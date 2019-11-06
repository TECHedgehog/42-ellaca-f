/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:35:14 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/06 14:00:23 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		l;
	char	*newstr;

	i = 0;
	l = 0;
	while (s[start++])
		i++;
	if (i > len)
		l = len;
	else
		l = i;
	newstr = malloc(l + 1);
	return (newstr);
}
