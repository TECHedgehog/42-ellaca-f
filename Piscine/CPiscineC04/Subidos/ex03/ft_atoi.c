/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:37:05 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/23 17:48:43 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_isspace(char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return (1);
	return (0);
}

void	char_converter(int i, char *str, int signcount, int *p_nb)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		*p_nb *= 10;
		*p_nb += str[i] - 48;
		i++;
	}
	while (signcount > 0)
	{
		*p_nb *= -1;
		signcount--;
	}
}

int		ft_atoi(char *str)
{
	unsigned int	i;
	unsigned int	signcount;
	int				nb;
	int				*p_nb;

	nb = 0;
	p_nb = &nb;
	i = 0;
	signcount = 0;
	while (ft_isspace(str, i))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signcount++;
		}
		i++;
	}
	char_converter(i, str, signcount, p_nb);
	return (nb);
}

int main()
{
	char	prueba[] = "  --+-0ahgdg87";
	
	printf("%d\n", ft_atoi(prueba));
	return (0);
}
