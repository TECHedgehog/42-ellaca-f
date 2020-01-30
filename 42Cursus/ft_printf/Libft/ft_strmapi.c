/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:26:43 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/19 15:01:58 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	int		i;

	if (s == NULL)
		return (0);
	if (!(newstr = malloc(sizeof(*s) * ft_strlen(s) + 1)))
		return (0);
	i = -1;
	while (s[++i])
		newstr[i] = f(i, s[i]);
	newstr[i] = '\0';
	return (newstr);
}
