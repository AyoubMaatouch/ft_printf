/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:51:14 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/07 21:36:55 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int    main(void)
{
	printf("|%10c|\n",'c');
	ft_printf("|%10c|\n",'c');	
	return (0);
}

