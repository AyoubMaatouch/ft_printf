/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:51 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/16 16:08:04 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
void	ft_puthex(va_list ap, char sep, struct s_flags s1)
{
	char *hex;
	unsigned long value;
	int len = 0;
	int zero = 0;
	int space = 0;

	if (sep == 'x')
	{
	value = va_arg(ap, unsigned int);
	hex = ft_hex(value, 0 , 0);
	len = ft_strlen(hex);
	if(s1.point && (s1.zero || s1.prec) && s1.prec > 0)
			zero = s1.prec - len ;
	if (s1.width)
		{
		if (zero > 0)
			space = s1.width - (zero + len);
		else if (!zero && (!s1.point || s1.prec < 0) && s1.zero && !s1.mins)
			zero = s1.width - len;
		else
			space = s1.width - len;
		}
	if (space && !s1.mins)
		ft_pspace(space);
	if (zero)
		ft_pzero(zero);
	if (s1.point && s1.prec == 0 && value == 0)
		s1.width ? ft_putchar(' '): 0;
	else
		ft_putstr_c(hex, 0);
	if (space && s1.mins)
		ft_pspace(space);

	//old	
		//ft_putstr_c(ft_hex(va_arg(ap, unsigned int), 0, 0), 0);
	}
	else if (sep == 'X') 
	{
			value = va_arg(ap, unsigned int);
	hex = ft_hex(value, 32 , 0);
	len = ft_strlen(hex);
	if(s1.point && (s1.zero || s1.prec) && s1.prec > 0)
			zero = s1.prec - len ;
	if (s1.width)
		{
		if (zero > 0)
			space = s1.width - (zero + len);
		else if (!zero && (!s1.point || s1.prec < 0) && s1.zero && !s1.mins)
			zero = s1.width - len;
		else
			space = s1.width - len;
		}
	if (space && !s1.mins)
		ft_pspace(space);
	if (zero)
		ft_pzero(zero);
	if (s1.point && s1.prec == 0 && value == 0)
		s1.width ? ft_putchar(' '): 0;
	else
		ft_putstr_c(hex, 0);
	if (space && s1.mins)
		ft_pspace(space);
		//old
		//ft_putstr_c(ft_hex(va_arg(ap, unsigned long), 32, 0), 0);
	}
	else
	{ 
	value = va_arg(ap, unsigned long);
	hex = ft_hex(value, 0 , 1);
	len = ft_strlen(hex);
	if(s1.point && (s1.zero || s1.prec) && s1.prec > 0)
			zero = s1.prec - len ;
	if (s1.width)
		{
		if (zero > 0)
			space = s1.width - (zero + len);
		else if (!zero && (!s1.point || s1.prec < 0) && s1.zero && !s1.mins)
			zero = s1.width - len;
		else
			space = (!value && (!s1.width || (s1.point &&!s1.prec))) ? s1.width - len + 1 : s1.width - len;
		}
		
	if (space && !s1.mins)
		ft_pspace(space);
	if (zero)
		ft_pzero(zero);
	if (s1.point && s1.prec == 0 && value == 0)
		ft_putstr_c("0x", 0);
	else
		ft_putstr_c(hex, 0);
	if (space && s1.mins)
		ft_pspace(space);
	
	}
	// old
	/*
	hex = ft_hex(va_arg(ap, unsigned long), 0, 1);
	len = ft_final_len(hex, s1);
	if ((len) > 0 && s1.mins == 0)
		ft_pspace(len);
	//here
			ft_putstr_c(hex , 0);

	if ((len) > 0 && s1.mins == 1)
		ft_pspace(len);
	}	
	*/	
}