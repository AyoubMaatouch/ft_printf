/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:18:40 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/14 14:59:11 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "ft_printf.h"

int    main(void)
{
	int a = 0, b = 0;
	a = ft_printf("|%4d|", 100);
		puts("\n");
	b = printf("|%4d|", 100);
	
	printf ("\n|%d| |%d| ", a, b);
//	printf("%s\n",ft_itoa_u(4294967295));
//	printf("%s\n",ft_itoa_u(0));
	return (0);
}
