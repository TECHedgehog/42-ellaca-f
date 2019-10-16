/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:26:26 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/15 14:36:32 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strstr(char *str, char *to_find)
{	
	unsigned int i;
	unsigned int j;
	char *c;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	else
		while (str[i] != '\0' && to_find[j] != '\0')
		{
			if (str[i] == to_find[j])
			{
				if (str[i] == to_find[0])
					*c = str[i];
				j++;
			}
			else
				j = 0;
			i++;
		}
	return (c);
}
