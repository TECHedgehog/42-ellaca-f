/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:28:25 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/02/26 17:17:01 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	int				fd;
	int				open;
	char			*str;
	struct s_list	*next;
}					t_list;
t_list				*ft_get_list(t_list **head, int fd);
int					get_next_line(int fd, char **line);
int					get_next_line_rec(int fd, char **line);
int					ft_get_pos(char *str, char *set);
int					ft_aux(char **line, t_list *tmp, int pos);
int					ft_supr_lst(t_list **head, t_list *to_del);
char				*ft_strdup(char *str);
char				*ft_strndup(char *str, int n);
char				*ft_strjoin_free(char *str1, char *str2, char c);
char				*ft_strjoin_free_aux(char *str1, char *str2, char c);
#endif
