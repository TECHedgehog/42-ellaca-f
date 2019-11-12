/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:11:45 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/11 12:04:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*newstr;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	k = i;
	l = i + j;
	newstr = malloc(l + 1);
	if (!newstr)
		return (0);
	j = 0;
	i = 0;
	while (l-- >= 0)
		newstr[j++] = (j < k) ? s1[j] : s2[i++];
	newstr[j] = '\0';
	return (newstr);
}