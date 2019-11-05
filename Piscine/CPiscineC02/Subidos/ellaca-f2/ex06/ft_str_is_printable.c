/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:08:22 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/14 19:07:33 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_printable(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	while (*(str + i) != '\0' && flag != 0)
	{
		if (*(str + i) >= 0 && *(str + i) < 32)
			flag = 0;
		else if (*(str + i) < 127)
			flag = 1;
		i++;
	}
	return (flag);
}
