/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:11:45 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/07 13:44:33 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		l;
	char	*newstr;

	i = 0;
	j = 0;
	l = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	l = i + j;
	newstr = malloc(l + 1);
	if (!newstr)
		return (0);
	j = 0;
	i = 0;
	while (l >= 0)
	{
		newstr[j] = (s1[j]) ? s1[j] : s2[i++];
		j++;
		l--;
	}
	return (newstr);
}

int main()
{
	printf("%s\n", ft_strjoin("hola", "que tal"));
}
