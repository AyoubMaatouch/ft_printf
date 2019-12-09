/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:55:30 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/08 17:04:36 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct flags ft_flag(char *format, struct flags s1)
{
	int i;

	i = 0;
	s1.width = 0;
	s1.mins = 0;
	if (format[i] == '-')
	{
		s1.mins = 1;
		i++;
	}
	if (ft_isdigit(format[i]))
	{
		s1.width = ft_atoi(c_toa(format[i]));
		i++;
		while (ft_isdigit(format[i]))
		{
			s1.width = (s1.width * 10) + ft_atoi(c_toa(format[i]));
			i++;
		}
	}
	s1.i = i;
	return (s1);
}
