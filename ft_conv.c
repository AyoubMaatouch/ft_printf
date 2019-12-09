/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:46:13 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/07 22:09:50 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_conv(const char *format, struct flags s1)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			s1 = ft_flag((char*)format + i, s1);
			i+= s1.i;	
			if (format[i] == 'c' || format[i] == 's')
				ft_charstr(s1.ap, s1, format[i]);
			else if (format[i] == 'd' || format[i] == 'i')
				ft_putdigit(s1.ap, 'd');
			else if (format[i] == 'u')
				ft_putdigit(s1.ap, 'u');
			else if (format[i] == 'x' || format[i] == 'X')
				ft_puthex(s1.ap, format[i]);
			else if (format[i] == 'p')
				ft_puthex(s1.ap, 'p');
			else
				write (1,&format[i],1);
			}
		else
			write (1,&format[i],1);
	i++;
	}
}