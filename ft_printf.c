/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:29:50 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/02 15:44:45 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr_c(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	
		write (1, '\0', 1);
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
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c' || format[i] == 's')
			{
				a += ft_putstr_c(format[i] == 'c' ? c_toa((va_arg(ap, int))): va_arg(ap, char*));
				i++;
			}
			if (format[i] == 'd' || format[i] == 'i')
			{
				a += ft_putstr_c(ft_itoa(va_arg(ap, int)));
				i++;
			}
			if (format[i] == 'u')
			{
				a += ft_putstr_c(ft_itoa_u(va_arg(ap, unsigned int)));
				i++;
			}
		}	
		write (1,&format[i],1);
		a = i++;
	}
	return (a);
}



int    main(void)
{
	printf("\n%d\n", ft_printf("hello c:(%c) s:(%s) d:(%d) u:(%u) ",'m' ,"ayoub", 1998, 4294967295));
	return (0);
}

