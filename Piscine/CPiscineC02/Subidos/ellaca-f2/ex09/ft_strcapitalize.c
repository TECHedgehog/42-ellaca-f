/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:36:05 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/14 19:02:39 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_conditions(int *i, int flag, char *str);

char	*ft_strcapitalize(char *str)
{
	int i[3];
	int flag;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (str[i[1]])
		i[1]++;
	while (*(str + i[0]) != '\0')
	{
		flag = 1;
		ft_conditions(i, flag, str);
		i[0]++;
	}
	return (str);
}

void	ft_conditions(int *i, int flag, char *str)
{
	while (i[2] <= i[1])
	{
		if (str[i[2]] >= 'A' && str[i[2]] <= 'Z')
			str[i[2]] = str[i[2]] + 32;
		i[2]++;
	}
	if (*(str + i[0]) >= 'a' && *(str + i[0]) <= 'z')
	{
		if ((*(str + i[0] - 1) >= '0' && *(str + i[0] - 1) <= '9') ||
			(*(str + i[0] - 1) >= 'a' && *(str + i[0] - 1) <= 'z') ||
			(*(str + i[0] - 1) >= 'A' && *(str + i[0] - 1) <= 'Z'))
			flag = 0;
		else
			flag = 1;
	}
	else
		flag = 0;
	if (flag == 1)
		*(str + i[0]) = *(str + i[0]) - 32;
}
