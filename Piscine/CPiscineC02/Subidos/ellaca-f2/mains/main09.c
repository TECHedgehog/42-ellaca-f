/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main09.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:12:43 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/14 18:57:27 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char *ft_strcapitalize(char *str);

int main()
{
	char str[] = "HolA mE llaM9o (eRic=lLa'ca";

	printf("%s\n", ft_strcapitalize(str));
	return (0);
}
