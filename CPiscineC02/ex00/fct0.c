/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:08:23 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/10 04:20:07 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src);

int main()
{
	char *dest;
	char *src;

	src = "Hola como estamos?";
	write(1, &*(ft_strcpy(dest, src)), 50);

	return (0);
}
