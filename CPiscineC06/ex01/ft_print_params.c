/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:17:00 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/18 12:58:37 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puststr(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		write(1, "\n", 2);
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	*str;
	int		j;

	j = 1;
	while (j < argc)
	{
		str = argv[j];
		ft_puststr(str);
		j++;
	}
	return (0);
}
