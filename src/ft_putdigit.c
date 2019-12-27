/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:38:38 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/26 21:56:08 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

// NEW FUNCTION

void	ft_putdigit(va_list ap, struct s_flags s1,  char sep)
{
	int value = 0;
	int len = 0;
	int zero = 0;
	int space = 0;
	
	if (sep == 'u')
		ft_putdigit_u(ap, s1);
	else
	{
	value = va_arg(ap, int);
	len = ft_strlen(ft_itoa(value));
	if(s1.point && (s1.zero || s1.prec) && s1.prec > 0)
			zero = s1.prec - len ;
	if (s1.width)
		{
		if (zero)
			space = value >= 0 ? s1.width - (zero + len):s1.width - (zero + (len + 1));
		else if (!zero && (!s1.point || s1.prec < 0) && s1.zero && !s1.mins)
			zero = value >= 0 ? s1.width - len : s1.width - (len + 1);
		else
			space = value >= 0 ? s1.width - (len) : s1.width - ((len + 1));
		}

	if (space && !s1.mins)
		ft_pspace(space);
	if (value < 0)
		ft_putchar('-');
	if (zero)
		ft_pzero(zero);
	if (s1.point &&s1.prec == 0 && value == 0)
		s1.width ? ft_putchar(' '): 0;
	else
		ft_putstr_c(ft_itoa(value), 0);
	if (space && s1.mins)
		ft_pspace(space);
	}
}










/// The OLD FUNCTION
/*
void	ft_putdigit(va_list ap, struct s_flags s1,  char sep)
{
	char	*digit;
	int		i;
	int		j;
	int		value;
	int		len;

	len = 0;
	j = 0;
	s1.zeroPrinted = 0;
	if (sep == 'u')
		ft_putdigit_u(ap, s1);
	else
	{
		value = va_arg(ap, int);
		if (value < 0 && (s1.zero || s1.prec > 0))
		{
			value  = (unsigned int)value * -1;
			digit = ft_itoa(value);
			len = s1.prec > 0 ? ft_strlen(digit) : ft_strlen(digit) + 1;
			if (!s1.prec || s1.prec == len || s1.width == (len + 1) || (!s1.width && (!s1.prec || s1.prec < 0)))
				ft_putchar('-');
			j = -1;
			if (len + 1 == s1.width && s1.prec == len)
				s1.width--;
		}
		else
		{
			digit = ft_itoa(value);
			len = ft_strlen(digit);
		}
		if ((i = s1.prec - len) > 0)
			{
				if (j < 0)
				{
				j += s1.width - s1.prec;
				if (j > 0)
					ft_pspace(j);
				ft_putchar('-');	
				s1.zeroPrinted = ft_pzero(i);
				}
				else
				{				
				j += s1.width - s1.prec;
				if (j > 0)
					ft_pspace(j);
			s1.zeroPrinted = ft_pzero(i);

				}
			}
		else if ((i = s1.width - len) > 0 && s1.mins == 0)
		  	 s1.zero == 0 ? ft_pspace(i) : ft_pzero(i);;	
		if (s1.prec == -1 && value == 0 && s1.width >= 0)
			s1.prec == -1 && s1.width == 0 ? 0 : ft_pspace(1);
		else
			ft_putstr_c(digit, 0);
			//s1.prec <= 0 ? ft_putstr_c(digit, 0):ft_putstr_d(digit, ft_strlen(digit));
		if ((i = s1.width - len) > 0 && s1.mins == 1 && !s1.zeroPrinted)
		   ft_pspace(i);	
	}
}
*/



void	ft_putdigit_u(va_list ap, struct s_flags s1)
{
		/*char *digit;
		int i;
		
		digit = ft_itoa_u(va_arg(ap, unsigned int));
		if ((i = s1.width - ft_strlen(digit)) > 1 && s1.mins == 0)
		   ft_pspace(i);
		ft_putstr_c(digit, 0);
		if ((i = s1.width - ft_strlen(digit)) > 1 && s1.mins == 1)
		   ft_pspace(i);
*/
	unsigned int value;
	int len = 0;
	int zero = 0;
	int space = 0;

	value = va_arg(ap, unsigned int);
	len = ft_strlen(ft_itoa_u(value));
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
		ft_putstr_c(ft_itoa_u(value), 0);
	if (space && s1.mins)
		ft_pspace(space);

}