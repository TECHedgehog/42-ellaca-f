/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:44:54 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/04/25 16:08:09 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isit(char const *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	size_t			k;
	unsigned int	start;

	if (s1 == 0)
		return (NULL);
	i = 0;
	k = 0;
	start = 0;
	while (ft_isit(set, s1[start]))
		start++;
	k = start;
	while (s1[k++])
		i++;
	k -= 2;
	while (ft_isit(set, s1[k--]) && k > start)
		i--;
	if (k <= start)
		return (ft_strdup(""));
	return (ft_substr(s1, start, i));
}
