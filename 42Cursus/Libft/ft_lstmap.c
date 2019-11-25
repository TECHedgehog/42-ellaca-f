/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:18:29 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/25 20:48:25 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlist;
	t_list *ptr;

	if (lst)
	{
		ptr = lst;
		ft_lstadd_back(&newlist, ft_lstnew(f(ptr->content)));
		ptr = ptr->next;
		while (ptr)
		{
			
		}
	}
	free(lst);
	return (newlist);
}
