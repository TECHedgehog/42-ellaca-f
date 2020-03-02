/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_width_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:42:53 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/03/02 18:32:15 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

/*char	*width_di(char *str, t_tab *tab)
{

}*/

char	*f_width_treatment(char *str, t_tab *tab)
{
	size_t aux;

	aux = tab->flag_width;
	if (tab->flag_width > (int)ft_strlen(str))
	{
		tab->s_flags = str;
		if (!(str = (char*)malloc(tab->flag_width + 1)))
			return (0);
		str[tab->flag_width] = '\0';
		tab->flag_width -= ft_strlen(tab->s_flags);
		tab->j = 0;
		while (tab->flag_width > 0)
		{
			str[tab->j++] = ' ';
			tab->flag_width--;
		}
		while (aux > tab->j)
		{
			str[tab->j] = tab->s_flags[tab->k++];
			tab->j++;
		}
		free(tab->s_flags);
	}
	return (str);
}
