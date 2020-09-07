/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:15:47 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/01 13:29:17 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h> 

int main()
{
	char	c;
	char	*str; 
	int		n1, n2, n3, n4, p1;
	int		d1;

	c = 'A';
	str = "adkncsduncsodincois    000]][][]";

	n1 = ft_printf("%+*.4c aaaaa %-05cDD\n", 5, c, c);
	n2 = printf("%+*.0c aaaaa %-05cDD\n", 5, c, c);

	n3 = ft_printf("%050.*sA\n", 4, str);
	n4 = printf("%050.*sA\n", 4, str);

	p1 = printf("% p\n", &str);

	d1 = printf("%10.4dA\n", 123);

	printf("%d = %d and %d = %d", n1, n2, n3, n4);
	printf("%c");

	return (0);
}
