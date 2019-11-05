/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:42:25 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/05 14:05:30 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	unsigned int	signcount;
	int				nb;
	int				flag;

	flag = 0;
	nb = 0;
	i = 0;
	signcount = 0;
	while (ft_isspace((char*)str, i))
		i++;
	if (str[i] == '-')
	{
		flag = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	if (flag == 1)
		nb *= -1;
	return (nb);
}
