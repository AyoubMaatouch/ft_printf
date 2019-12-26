/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:55:30 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/26 22:09:25 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_is_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

struct s_flags ft_flag(char *format, struct s_flags s1, va_list ap)
{
	int i;
	int value;
	int value_p;

	i = 0;
	s1.width = 0;
	s1.mins = 0;
	s1.prec = 0;
	s1.zero = 0;
	s1.isempty = 0;
	s1.point = 0;
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
		s1.point = 1;
		if (!ft_isdigit(format[i - 1]) && format[i - 1] != '*' && !ft_isdigit(format[i + 1]) && format[i + 1] != '*')
			s1.isempty = 1;
		i++;
		if (format[i] == '*')
			{
				value_p = va_arg(s1.ap, int);
				if (value_p < 0)
					s1.prec = -1;
				else
					s1.prec = value_p;
				i++;
			}
		else if (ft_isdigit(format[i]) && ft_atoi(&format[i]))
		{
			s1.prec = ft_atoi(c_toa(format[i++]));
			while (ft_isdigit(format[i]))
				s1.prec = (s1.prec * 10) + ft_atoi(c_toa(format[i++]));
		}
		else if (!ft_isdigit(format[i]) || ft_atoi(&format[i]) == 0)
			{ 
				s1.prec = -1;
				if (!ft_is_flag(format[i]))
					i++;
			}
	}
	s1.i = i;
	return (s1);
}

int	ft_pspace(int value)
{
	 int i;

	i = 0;
	while (value > 0)
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
	while (value > 0)
	{
		write(1, "0", 1);
		g_count++;
		value--;
	}
	return (1);
}