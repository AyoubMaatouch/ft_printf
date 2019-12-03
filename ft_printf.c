/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:29:50 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/03 21:44:20 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr_c(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	
		write (1, "\0", 1);
	return (i);
}
char	*c_toa(char c)
{
	char *ret;

	ret = malloc(sizeof(char) + 1);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

int	ft_printf(const char *format, ...)
{
int i, a;
va_list ap;

	i  = 0;
	a = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] != '%' || format[i - 1] != '%'))
		{
			i++;
			if (format[i] == 'c' || format[i] == 's')
				ft_putstr_c(format[i] == 'c' ? c_toa((va_arg(ap, int))): va_arg(ap, char*));
			if (format[i] == 'd' || format[i] == 'i')
				ft_putstr_c(ft_itoa(va_arg(ap, int)));
			if (format[i] == 'u')
				ft_putstr_c(ft_itoa_u(va_arg(ap, unsigned int)));
			if (format[i] == 'x' || format[i] == 'X')
				ft_putstr_c(format[i] == 'x' ? ft_hex(va_arg(ap, unsigned int), 0, 0) : ft_hex(va_arg(ap, unsigned int), 32, 0));
			if (format[i] == 'p')
				ft_putstr_c(ft_hex(va_arg(ap, unsigned long), 0, 1));
			i++;
		}
		else
		{
			write (1,&format[i],1);
			i++;
		}
	}
	return (a);
}



int    main(void)
{
	char a;
	printf("%%c\n",'m');
	ft_printf("%%c\n",'m');
	return (0);
}

