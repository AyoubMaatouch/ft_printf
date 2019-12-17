/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:18:40 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/17 18:23:54 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "ft_printf.h"

int    main(void)
{
	int a = 0, b = 0;
	a = ft_printf("|%4.d|", 10);
		puts("\n");
	b = printf("|%4.d|", 10);
	
	printf ("\n|%d| |%d| ", a, b);
//	printf("%s\n",ft_itoa_u(4294967295));
//	printf("%s\n",ft_itoa_u(0));
	return (0);
}
