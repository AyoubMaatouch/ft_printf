/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:29:50 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/12 21:09:05 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
	write (1, &c, 1);
}

int ft_putstr_c(char *str, int index)
{
	int i;

	i = 0;
	if (!index)
	{
		while (str[i] != '\0')
		{
			write (1, &str[i], 1);
			i++;
		}
	}
	if (index)
	{
		while (i < index &&str[i] != '\0')
		{
			write (1, &str[i], 1);
			i++;
		}
		write(1, "\0", 1);
	}
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
	int a;
	va_list ap;
	struct s_flags s1;
	
	a = 0;
	va_start(ap, format);
	va_copy(s1.ap, ap);
	ft_conv(format, s1);
	va_end(s1.ap);	
	return (a);
}
