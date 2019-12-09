/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:51:14 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/09 18:50:13 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
int    main(void)
{
	printf("|%-10c|\n", 'c');
	ft_printf("|%-10c|\n",'c');	
	printf("|%1s|\n","hona");	
	ft_printf("|%1s|\n","hona");
	printf("|%-1s|\n","hello");
	ft_printf("|%-1s|\n","hello");
	return (0);
}

