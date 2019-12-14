/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:18:40 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/13 21:24:32 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "ft_printf.h"

int    main(void)
{
	int a = 0, b = 0;
	a = ft_printf("ft %s\n", "%15d");
	b = printf("pr %s\n", "%15d");
	
	printf ("|%d| |%d| ", a, b);
//	printf("%s\n",ft_itoa_u(4294967295));
//	printf("%s\n",ft_itoa_u(0));
	return (0);
}

