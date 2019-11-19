/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:11:45 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/19 14:55:49 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
