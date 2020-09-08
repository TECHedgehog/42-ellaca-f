/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:21:34 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/26 12:21:42 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ptr;

	ptr = *lst;
	while (*lst)
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = ptr;
	}
	lst = NULL;
}
