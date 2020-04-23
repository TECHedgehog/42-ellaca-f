/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:47:22 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/04/23 22:26:29 by ellaca-f         ###   ########.fr       */
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
	char		*s_flags;
	va_list		punt_arg;
	int			len;
	size_t		i;
	size_t		j;
	size_t		k;
	char		*specifiers;
	int			sp_di;
	int			sp_x;
	int			sp_c;
	int			sp_p;
	int			sp_u;
	int			sp_s;
	char		*punt_spec;
	char		*flags;
	int			flags_on;
	int			flag_minus;
	int			flag_zero;
	int			flag_precision_pos;
	int			flag_precision;
	int			flag_star;
	int			flag_width;
	int			is_negative;
}				t_tab;

int				ft_printf(const char *formats, ...);
t_tab			*tab_initializer(t_tab *tab);
t_tab			*tab_reinitializer(t_tab *tab);
t_tab			*processor(t_tab *tab);
t_tab			*processor_flags(t_tab *tab);
t_tab			*processor_specs(t_tab *tab);
char			*processor_di(t_tab *tab);
t_tab			*printer(char *str, t_tab *tab);
char			*flags_treatment_di(char *str, t_tab *tab);
char			*noflags_negative(char *str, t_tab *tab);
char			*di_zero_minus(char *str, t_tab *tab, size_t aux);
char			*di_width_minus(char *str, t_tab *tab, size_t aux);
char			*di_prec_minus(char *str, t_tab *tab, size_t aux, size_t index);
/*
void			processor_x(t_tab *tab);
void			processor_c(t_tab *tab);
void			processor_s(t_tab *tab);
void			processor_p(t_tab *tab);
void			processor_u(t_tab *tab);*/

#endif
