/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 03:23:43 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/15 04:45:01 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
	char s1[] = "asdfhddfki";
	char s2[] = "asdfhddfki";
	unsigned int n = 5;
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));

	return (0);
}
