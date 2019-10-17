/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:26:26 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/17 05:03:29 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	strlen_cmp(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (to_find[j])
		j++;
	if (i < j)
		return (1);
	return (0);
}

char *ft_strstr(char *str, char *to_find)
{	
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (strlen_cmp(str, to_find))
		return (0);
	if (str[0] == '\0')
		return (0);
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && to_find[j] != '\0')
				j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
