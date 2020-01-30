/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:47:22 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/01/30 17:23:51 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_tab
{
	const char	*formats;
	char		*f_copy;
	char		*f_copy2;
	va_list		punt_arg;
	int			len;
	size_t		i;
	char		*specifiers;
	char		*flags;
}				t_tab;

int				ft_printf(const char *formats, ...);
t_tab			*tab_initializer(t_tab *tab);

#endif
