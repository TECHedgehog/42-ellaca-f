/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:08:56 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/26 12:09:06 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem1;

	if (!(elem1 = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		elem1->content = NULL;
	else
		elem1->content = content;
	elem1->next = NULL;
	return (elem1);
}
