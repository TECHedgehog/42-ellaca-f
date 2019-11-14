/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:35:14 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/12 13:19:56 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = malloc(len + 1);
	if (!newstr)
		return (0);
	newstr[len] = '\0';
	while (len-- > 0)
		newstr[i++] = s[start++];
	return (newstr);
}
