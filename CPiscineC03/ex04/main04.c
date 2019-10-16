/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:11:09 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/15 14:30:01 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strstr(char *str, char *to_find);

int main()
{
	char str[] = "holaComoEstamos";
	char to_find[] = "";

	printf("%s\n", ft_strstr(str, to_find));
	return (0);
}
