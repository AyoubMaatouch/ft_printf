/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:18:40 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/27 15:49:49 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "ft_printf.h"

int    main(void)

{
	char *s = "hello mother fucker";
	int a = 0, b = 0;
	a = ft_printf("|Bla bla %%%%%%%%%% %05.*d| %*.*s",-10, 42, 20, 3, NULL);
		puts("\n");
	b = printf("|Bla bla %%%%%%%%%% %05.*d| %*.*s",-10, 42, 20, 3, NULL);
	
	printf ("\n|%d| |%d| ", a, b);
//	printf("%s\n",ft_itoa_u(4294967295));
//	printf("%s\n",ft_itoa_u(0));
	return (0);
}