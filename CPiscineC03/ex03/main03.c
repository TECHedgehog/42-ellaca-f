/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:02:31 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/15 09:39:17 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

int main()
{
	char src[] = "asdf";
	char dest[] = "1234";
	unsigned int nb = 2;

	printf("%s\n", ft_strncat(dest, src, nb));
	printf("%s\n", strncat(dest, src, nb));
	return (0);
}
