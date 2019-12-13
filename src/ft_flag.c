/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:55:30 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/13 16:35:03 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

struct s_flags ft_flag(char *format, struct s_flags s1, va_list ap)
{
	int i;
	int value;

	i = 0;
	s1.width = 0;
	s1.mins = 0;
	s1.prec = 0;
	s1.zero = 0;
	if (format[i] == '-')
	{
		s1.mins = 1;
		i++;
	}
	while (ft_isdigit(format[i]) && ft_atoi(c_toa(format[i])) == 0)
	{
		s1.zero = 1;
		i++;
	}
	if (format[i] == '*')
	{
		value = va_arg(ap, int);
		if (value < 0)
		{
			s1.mins = 1;
			s1.width = value * -1;
		}
		else
			s1.width = value;
		i++;
		va_copy(s1.ap, ap);
	}
	if (ft_isdigit(format[i]))
	{
		s1.width = ft_atoi(c_toa(format[i++]));
		while (ft_isdigit(format[i]))
			s1.width = (s1.width * 10) + ft_atoi(c_toa(format[i++]));
	}
	if (format[i] == '.')
	{
		i++;
		if (ft_isdigit(format[i]))
		{
			s1.prec = ft_atoi(c_toa(format[i++]));
			while (ft_isdigit(format[i]))
				s1.prec = (s1.prec * 10) + ft_atoi(c_toa(format[i++]));
		}
	}
	s1.i = i;
	return (s1);
}

int	ft_pspace(int value)
{
	 int i;

	i = 0;
	while (value)
	{
		write(1, " ", 1);
		i++;
		g_count++;
		value--;
	}
	return (i);
}


int	ft_pzero(int value)
{
	 int i;

	i = 0;
	while (value)
	{
		write(1, "0", 1);
		i++;
		g_count++;
		value--;
	}
	return (i);
}