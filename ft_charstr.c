/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:22:25 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/09 18:49:33 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
void	ft_charstr(va_list ap, struct flags s1, char format)
{
	int len;
	char *s;
	int i;

	len = 0;
	if (format == 'c')
	{
		if (s1.width > 1 && s1.mins == 0)
		{
			while (--s1.width)
			   write(1, " ", 1);
		}
		ft_putstr_c(c_toa(va_arg(ap, int)));
		if (s1.width > 1 && s1.mins == 1)
		{
			while (--s1.width)
				write(1, " ", 1);
		}
	}
	else
	{
		s = va_arg(ap, char*);
		len = ft_strlen(s);
		if ((i = s1.width - len) > 1 && s1.mins == 0)
		{
			while (i--)
			   write(1, " ", 1);
		}
		ft_putstr_c(s);
		if ((i = s1.width - len) > 1 && s1.mins == 1)
		{
			while (i--)
			   write(1, " ", 1);
		}
	}
}
