/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:29:16 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/14 18:00:27 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int main()
{
	unsigned int n;
	char src[] = "djf";
	char dest[7];
	int i;

	i = 0;
	n = 7;
	ft_strncpy(dest, src, n);
	while (i < n)
	{
		write(1, &dest[i], 1);
		i++;
	}
}
