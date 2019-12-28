/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:29:50 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/28 17:54:46 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAX 2147483647

int	ft_printf(const char *format, ...)
{
	int				a;
	va_list			ap;
	struct s_flags	s1;

	g_count = 0;
	a = 0;
	va_start(ap, format);
	va_copy(s1.ap, ap);
	ft_conv(format, s1);
	va_end(s1.ap);
	if (g_count > MAX || g_error)
		return (-1);
	return (g_count);
}
