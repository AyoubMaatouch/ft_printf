/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:51:14 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/12 21:13:59 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
int    main(void)
{
	printf("pr|%12u|\n", -10);
	ft_printf("ft|%12u|\n", -10);
	return (0);
}

