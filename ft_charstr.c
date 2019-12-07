/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:22:25 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/07 22:09:47 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_charstr(va_list ap, struct flags s1, char format)
{
	//printf("%d\n", s1.width);
	if (format == 'c')
	{
		if (s1.width > 1)
			while (--s1.width)
			   write(1, " ", 1);	
		ft_putstr_c(c_toa(va_arg(ap, int)));
	}
	else
		ft_putstr_c(va_arg(ap, char*));
	
}
