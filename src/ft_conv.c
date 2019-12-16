/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:46:13 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/16 16:07:45 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
void	ft_conv(const char *format, struct s_flags s1)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			s1 = ft_flag((char*)format + i, s1, s1.ap);
			i+= s1.i;
			if (format[i] == 'c' || format[i] == 's')
				format[i] == 'c' ? ft_char(s1.ap, s1) : ft_str(s1.ap, s1);
			else if (format[i] == 'd' || format[i] == 'i')
				ft_putdigit(s1.ap, s1, 'd');
			else if (format[i] == 'u')
				ft_putdigit(s1.ap, s1, 'u');
			else if (format[i] == 'x' || format[i] == 'X')
				ft_puthex(s1.ap, format[i], s1);
			else if (format[i] == 'p')
				ft_puthex(s1.ap, 'p', s1);
			else
				ft_putchar(format[i]);
			}
		else
			ft_putchar(format[i]);
	i++;
	}
}
