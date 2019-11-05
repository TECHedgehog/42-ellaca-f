/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:48:08 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/23 20:36:50 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_strcmp(char *str1, char *str2)
{
	int k;

	k = 0;
	while (str1[k] != '\0')
	{
		if (str1[k] != str2[k])
			return (str1[k] - str2[k]);
		k++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		j;
	char	*aux;
	int		aux1;

	aux1 = 0;
	j = 0;
	while (++j < argc - 1)
	{
		if (ft_strcmp(argv[j], argv[j + 1]) > 0)
		{
			aux = argv[j];
			argv[j] = argv[j + 1];
			argv[j + 1] = aux;
			aux1++;
		}
		if (aux1 == 1)
		{
			j = 0;
			aux1 = 0;
		}
	}
	j = 0;
	while (++j < argc)
		ft_putstr(argv[j]);
	return (0);
}
