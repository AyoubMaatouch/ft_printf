/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:46:13 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/06 13:51:40 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_conv(const char *format, va_list ap)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c' || format[i] == 's')
				ft_charstr(format[i], ap);
			else if (format[i] == 'd' || format[i] == 'i')
				ft_putdigit(ap, 'd');
			else if (format[i] == 'u')
				ft_putdigit(ap, 'u');
			else if (format[i] == 'x' || format[i] == 'X')
				ft_puthex(ap, format[i]);
			else if (format[i] == 'p')
				ft_puthex(ap, 'p');
			else
				write (1,&format[i],1);
			}
		else
			write (1,&format[i],1);
	i++;
	}
}
