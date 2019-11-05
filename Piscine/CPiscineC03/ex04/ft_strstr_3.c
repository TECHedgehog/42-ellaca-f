/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:20:23 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/15 12:22:38 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char *found;
	unsigned int i;
	unsigned int j;
	unsigned int aux[3];

	aux[0] = 0;
	aux[1] = 0;
	aux[2] = 0;
	i = 0;
	j = 0;
	while (to_find[j])
		j++;
	while (str[i])
	{
		aux[0] = 0;
		if (to_find[aux[0]] == str[i])
		{
			str[i] = *found;
			aux[1] = i;
			aux[2] = 0;
			while (aux[0] <= j && to_find[aux[0]] == str[aux[1]])
			{
				aux[2] = 1;
				aux[1]++;
				aux[0]++;
			}
			if (aux[2] == 1)
				return (found);
		}
		else if (to_find[0] == '\0')
			found = str;
		else
			found = 0;
		i++;
	}
}
