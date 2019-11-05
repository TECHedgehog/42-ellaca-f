/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:32:50 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/14 19:54:06 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);

int main()
{
	char s1[] = "abc(j";
	char s2[] = "abcDe";

	printf("%d\n", strcmp(s1, s2));
	printf("%i\n", ft_strcmp(s1, s2));
	return (0);
}
