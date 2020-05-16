/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 10:54:18 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/05/07 13:44:56 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

char	*str_is_null(t_tab *tab, char *str, char *c)
{
	char	*null_str;

	null_str = "(null)";
	tab->is_null_s = 5;
	free(str);
	if (!(str = (char*)malloc(7)))
		return (NULL);
	str = ft_strcpy(str, null_str);
	if (tab->flag_precision == (int)ft_strlen(str)
		&& tab->flag_width > 0)
		tab->sp_s = 3;
	return (str);
}

char	*activator_strings(t_tab *tab, char *str, char *c)
{
	int		s_1;
	int		s_2;

	str = ft_strcpy(str, c);
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
		if (!(str = (char*)malloc(sizeof(c))))
			return (NULL);
		if (c == NULL)
		{
			str = str_is_null(tab, str, c);
			return (str);
		}
		str = activator_strings(tab, str, c);
		return (str);
	}
	n = va_arg(tab->punt_arg, int);
	if (!(c = (char*)ft_calloc(1, sizeof(char))))
		return (NULL);
	c[0] = (char)n;
	activator_char(tab, c);
	return (c);
}
