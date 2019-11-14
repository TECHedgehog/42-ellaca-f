/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:57 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/14 21:03:01 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		n;
	int		l;
	char	**newstr;

	i = 0;
	j = 0;
	n = 0;
	l = 0;
	while (s[i])
	{
		(s[i++] == c) ? ++n : 0;
		while (s[i] == c)
			i++;
	}
	*newstr = malloc(sizeof(char *) * n);
	i = 0;
	while (n-- > 0)
	{
		j = 0;
		while (s[j] != c)
			j++;
		ft_substr(newstr[l++], i, j - i);
		i = j;
	}
	return (newstr);
}
