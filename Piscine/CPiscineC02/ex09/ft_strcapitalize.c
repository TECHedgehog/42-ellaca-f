/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:36:05 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/11 10:46:32 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_conditions(int i, int flag, char *str);

char	*ft_strcapitalize(char *str)
{
	int i;
	int flag;

	i = 0;
	while (*(str + i) != '\0')
	{
		flag = 1;
		ft_conditions(i, flag, str);
		i++;
	}
	return (str);
}

void	ft_conditions(int i, int flag, char *str)
{
	if (*(str + i) >= 'a' && *(str + i) <= 'z')
	{
		if ((*(str + i - 1) >= '0' && *(str + i - 1) <= '9') ||
			(*(str + i - 1) >= 'a' && *(str + i - 1) <= 'z') ||
			(*(str + i - 1) >= 'A' && *(str + i - 1) <= 'Z'))
			flag = 0;
		else
			flag = 1;
	}
	else if (*(str + i) >= 'A' && *(str + i) <= 'Z')
	{
		if ((*(str + i - 1) >= '0' && *(str + i - 1) <= '9') ||
			(*(str + i - 1) >= 'a' && *(str + i - 1) <= 'z') ||
			(*(str + i - 1) >= 'A' && *(str + i - 1) <= 'Z'))
		{
			*(str + i) = *(str + i) + 32;
			flag = 0;
		}
	}
	else
		flag = 0;
	if (flag == 1)
		*(str + i) = *(str + i) - 32;
}
