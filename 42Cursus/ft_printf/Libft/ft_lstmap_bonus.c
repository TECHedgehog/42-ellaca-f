/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:02:16 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/26 12:04:10 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *ls, void *(*f)(void*), void (*del)(void*))
{
	t_list	*newlist;
	t_list	*ptr;
	t_list	*aux;

	if (!ls && !del)
		return (NULL);
	aux = ls;
	if (!(newlist = ft_lstnew(f(aux->content))))
		return (NULL);
	aux = aux->next;
	while (aux)
	{
		if (!(ptr = ft_lstnew(f(aux->content))))
			return (NULL);
		ft_lstadd_back(&newlist, ptr);
		aux = aux->next;
	}
	return (newlist);
}
