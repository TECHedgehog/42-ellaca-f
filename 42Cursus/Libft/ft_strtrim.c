/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:44:54 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/07 17:43:28 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_isit(char const *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	unsigned int	start;
	int				ctrl;

	i = 0;
	start = 0;
	ctrl = 1;
	while (ft_isit(set, s1[start]))
		start++;
	i = start;
	while (s1[i])
		i++;
	while (ft_isit(set, s1[i]))
		i--;
	return (ft_substr(s1, start, i - start + 1));
}
