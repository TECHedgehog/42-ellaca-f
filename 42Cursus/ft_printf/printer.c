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

char	*flags_treatment(char *str, t_tab *tab)
{
	if (tab->sp_di)
		str = flags_treatment_di(str, tab);
	return (str);
}

void	print_it(char *str, t_tab *tab)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		tab->len++;
		i++;
	}
}

t_tab	*printer(char *str, t_tab *tab)
{
	int i;

	i = 0;
	if (tab->flags_on || (!tab->flags_on && tab->is_negative))
		str = flags_treatment(str, tab);
	print_it(str, tab);
	free(str);
	return (tab);
}
