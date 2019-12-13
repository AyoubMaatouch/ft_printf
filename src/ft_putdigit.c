/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:38:38 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/13 20:34:12 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putdigit(va_list ap, struct s_flags s1,  char sep)
{
	char	*digit;
	int		i;
	int		value;
	int		len;
	if (sep == 'd')
	{
		value = va_arg(ap, int);
		if (value < 0 && s1.zero)
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
		if ((i = s1.width - len) > 1 && s1.mins == 0)
		   s1.zero == 0 ? ft_pspace(i) : ft_pzero(i);	
		ft_putstr_c(digit, 0);
		if ((i = s1.width - len) > 1 && s1.mins == 1)
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
