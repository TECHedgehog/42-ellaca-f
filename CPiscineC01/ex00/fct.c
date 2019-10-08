/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:20:32 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/10/04 14:54:52 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b);

int main()
{
	int div;
	int mod;
	int *a;
	int *b;

	div = 10;
	mod = 3;
	a = &div;
	b = &mod;
	ft_ultimate_div_mod(a, b);
	return 0;
}
