/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:29:50 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/05 15:50:35 by aymaatou         ###   ########.fr       */
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
	ft_conv(format, ap);
	va_end(ap);	
	return (a);
}
