/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:49:43 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/25 17:27:58 by ellaca-f         ###   ########.fr       */
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
