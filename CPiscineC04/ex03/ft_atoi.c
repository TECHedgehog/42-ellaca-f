/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:37:05 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/17 01:21:16 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	unsigned int i;
	unsigned int signcount;
	int nb;
	
	nb = 0;
	i = 0;
	signcount = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				nb *= 10; 
				nb += str[i] - 48;
				i++;
			}
			return (nb);
		}
		else if (str[i] == '-')
		{
			nb *= -1;
			i++;
		}
		else
			i++;
	}
	return (0);
}
