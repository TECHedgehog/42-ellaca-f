/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 04:50:54 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/10 09:40:15 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	while (*(str + i) != '\0' && flag != 0)
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			flag = 1;
		else if (*(str + i) >= 'a' && *(str + i) <= 'z')
			flag = 1;
		else
			flag = 0;
		i++;
	}
	return (flag);
}
