/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:00:40 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/10 10:05:56 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_uppercase(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	while (*(str + i) != '\0' && flag != 0)
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			flag = 1;
		else
			flag = 0;
		i++;
	}
	return (flag);
}
