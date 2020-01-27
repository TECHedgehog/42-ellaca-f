/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:22:52 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/01/27 17:43:45 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	while (s1[i])
		i++;
	dst = malloc(i + 1);
	if (!dst)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i[4];
	char	*newstr;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	while (s1[i[0]])
		i[0]++;
	while (s2[i[1]])
		i[1]++;
	i[2] = i[0];
	i[3] = i[0] + i[1];
	if (!(newstr = malloc(i[3] + 1)))
		return (0);
	i[1] = 0;
	while (i[3]-- >= 0)
	{
		newstr[i[1]] = (i[1] < i[2]) ? s1[i[1]] : *s2++;
		i[1]++;
	}
	newstr[i[1] - 1] = '\0';
	return (newstr);
}

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

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

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
