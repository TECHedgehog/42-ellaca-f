/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:42:28 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/18 12:59:12 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
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

	j = argc - 1;
	while (j > 0)
	{
		str = argv[j];
		ft_putstr(str);
		j--;
	}
	return (0);
}
