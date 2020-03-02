/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:51:57 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/03/02 18:01:06 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

/*char	*f_star_treatment(char *str, t_tab *tab)
{
	
}

char	*f_precision_treatment(char *str, t_tab *tab)
{

}

char	*f_zero_treatment(char *str, t_tab *tab)
{

}

char	*f_minus_treatment(char *str, t_tab *tab)
{

}*/



t_tab	*printer(char *str, t_tab *tab)
{
	int i;

	i = 0;
	if (tab->flag_width > 0)
		str = f_width_treatment(str, tab);
	//if (tab->flag_minus >= 0)
	//	str = f_minus_treatment(str, tab);
	while (str[i])
	{
		write(1, &str[i], 1);
		tab->len++;
		i++;
	}
	free(str);
	return (tab);
}
