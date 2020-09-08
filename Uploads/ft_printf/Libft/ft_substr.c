/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:35:14 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/21 20:43:56 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*newstr;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	if (start > i)
		return (newstr = ft_calloc(1, 1));
	i = 0;
	if (!(newstr = malloc(len + 1)))
		return (0);
	newstr[len] = '\0';
	while (len-- > 0)
		newstr[i++] = s[start++];
	return (newstr);
}
