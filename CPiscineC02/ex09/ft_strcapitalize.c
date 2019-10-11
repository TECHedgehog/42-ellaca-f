/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:36:05 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/10 11:25:29 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		else if (*(str + i) >= 'a' && *(str + i) <= 'z')
		{
			if (*(str + i - 1) >= 0 && *(str + i -1) < '0')
				*(str + i) = *(str + i) - 32;
			else if (*(str + i - 1) > '9' && *(str + i - 1) < 'A')
				*(str + i) = *(str + i) - 32;
			else if (*(str + i - 1) > 'z' && *(str + i - 1) <= 127)
				*(str + i) = *(str + i) - 32;
		else if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) = *(str + i) + 32;			
		i++;
	}
	return (str);
}

int main()
{
	char str[] = "hola, ¿cómo estás? 42palabras cuarenta-y-dos; cincuenta+y+uno";

	ft_strcapitalize(str);
	printf("%s\n", str);
	return (0);
}
