/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:46:13 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/28 04:24:25 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_conv(const char *format, struct s_flags s1)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			s1 = ft_flag((char*)format, s1, s1.ap);
			format += s1.i;
			if (*format == 'c' || *format == 's')
				*format == 'c' ? ft_char(s1.ap, s1) : ft_str(s1.ap, s1);
			else if (*format == 'd' || *format == 'i')
				ft_putdigit(s1.ap, s1);
			else if (*format == 'u')
				ft_putdigit_u(s1.ap, s1);
			else if (*format == 'x' || *format == 'X' || *format == 'p')
				ft_send_fo_ft(s1.ap, s1, *format);
			else if (*format == '%')
				ft_p(s1);
			else
				ft_putchar(*format);
		}
		else
			ft_putchar(*format);
		format++;
	}
}

void	ft_send_fo_ft(va_list ap, struct s_flags s1, char c)
{
	if (c == 'x')
		ft_put_x(ap, s1);
	else if (c == 'X')
		ft_put_xx(ap, s1);
	else
		ft_put_p(ap, s1);
}
