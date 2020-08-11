/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:54:18 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/08/11 19:51:22 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

char	*activator_strings(t_tab *tab, char *str, char *c)
{
	int		s_1;
	int		s_2;

	str = ft_strcpy(str, c);
	tab->is_null_s = (c[0] == '\0') ? 1 : 0;
	s_1 = (tab->flag_width < (int)ft_strlen(str)) ? 1 : 0;
	s_2 = (!(tab->flag_precision < (int)ft_strlen(str))) ? 1 : 0;
	tab->sp_s = (tab->flag_precision && tab->flag_width) ? 2 : 1;
	tab->flag_width = (s_1 && s_2) ? (int)ft_strlen(str) : tab->flag_width;
	return (str);
}

void	activator_char(t_tab *tab, char *c)
{
	tab->sp_c = (c[0] == '\0') ? 2 : 1;
	tab->is_null = (c[0] == '\0') ? 1 : 0;
}

char	*processor_cs(t_tab *tab)
{
	char	*c;
	char	*str;
	int		n;

	n = 0;
	tab->sp_on++;
	if (tab->formats[tab->i] == 's')
	{
		c = va_arg(tab->punt_arg, char *);
		if (!(str = (char*)malloc(ft_strlen(c) + (size_t)tab->flag_width)))
			return (NULL);
		if (c == NULL)
		{
			str = activator_strings(tab, str, "(null)");
			return (str);
		}
		str = activator_strings(tab, str, c);
		return (str);
	}
	n = va_arg(tab->punt_arg, int);
	if (!(c = (char*)ft_calloc(2, sizeof(char))))
		return (NULL);
	c[0] = (char)n;
	activator_char(tab, c);
	return (c);
}
