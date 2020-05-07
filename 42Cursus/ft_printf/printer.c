/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:51:57 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/05/07 13:28:04 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

char	*flags_treatment_all(char *str, t_tab *tab)
{
	if (tab->sp_di || tab->sp_u)
		str = flags_treatment(str, tab);
	else if (tab->sp_x || tab->sp_p)
		str = flags_treatment(str, tab);
	else if (tab->sp_c)
		str = flags_treatment(str, tab);
	else if (tab->sp_s > 0 || tab->is_null_s == 5)
		str = flags_treatment(str, tab);
	return (str);
}

void	print_it(char *str, t_tab *tab)
{
	int i;

	i = 0;
	if (tab->sp_c == 2)
	{
		if (tab->flag_width < 1)
			write(1, &str[0], 1);
		while (i < tab->flag_width)
		{
			write(1, &str[i++], 1);
			tab->len++;
		}
	}
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			tab->len++;
			i++;
		}
	}
}

t_tab	*printer(char *str, t_tab *tab)
{
	if ((tab->flags_on || (!tab->flags_on && tab->is_negative)))
		str = flags_treatment_all(str, tab);
	print_it(str, tab);
	if (tab->is_null_s == 5)
		tab->len -= tab->is_null_s;
	free(str);
	return (tab);
}
