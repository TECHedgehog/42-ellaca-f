/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:57 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/07 18:06:33 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

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
		(s[i++] == c) ? ++n : 0;
	*newstr = malloc(8 * n);
	while (n-- > 0)
	{
		j = 0;
		while (s[j] != c)
			j++;
		ft_substr(newstr[l++], i, j);
		i = j;
	}
	return (newstr);
}
