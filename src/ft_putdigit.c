/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:38:38 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/16 21:05:06 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putdigit(va_list ap, struct s_flags s1,  char sep)
{
	char	*digit;
	int		i;
	int		j;
	int		value;
	int		len;

	if (sep == 'd')
	{
		value = va_arg(ap, int);
		if (value < 0 && (s1.zero || s1.prec > 0))
		{
			value  = (unsigned int)value * -1;
			digit = ft_itoa(value);
			len = ft_strlen(digit) + 1;
			ft_putchar('-');
		}
		else
		{
			digit = ft_itoa(value);
			len = ft_strlen(digit);
		}
		if ((i = s1.prec - len) > 0)
			{
				j = s1.width - s1.prec;
				if (j > 0)
					ft_pspace(j);
				ft_pzero(i);
			}
		else if ((i = s1.width - len) > 0 && s1.mins == 0)
		  	 s1.zero == 0 ? ft_pspace(i) : ft_pzero(i);	
		s1.prec <= 0 ? ft_putstr_c(digit, 0):ft_putstr_d(digit, s1.prec);
		if ((i = s1.width - len) > 0 && s1.mins == 1)
		   ft_pspace(i);	
	}
	else
	{
		digit = ft_itoa_u(va_arg(ap, unsigned int));
		if ((i = s1.width - ft_strlen(digit)) > 1 && s1.mins == 0)
		   ft_pspace(i);	
		ft_putstr_c(digit, 0);
		if ((i = s1.width - ft_strlen(digit)) > 1 && s1.mins == 1)
		   ft_pspace(i);
	}
	if (digit)
		free(digit);	
}
