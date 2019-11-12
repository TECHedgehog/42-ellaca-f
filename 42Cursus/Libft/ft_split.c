/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:57 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/11 17:17:29 by marvin           ###   ########.fr       */
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

int main()
{
	int i = 0;

	while (i++ < 4)
	{
		printf("%s\n", ft_split("abcccdefgchicj", 'c')[i]);
	}
}