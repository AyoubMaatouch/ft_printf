/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:10:42 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/27 22:08:30 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_char(va_list ap, struct s_flags s1)
{
	if (s1.width > 1 && s1.mins == 0)
		ft_pspace(s1.width - 1);
	ft_putchar(va_arg(ap, int));
	if (s1.width > 1 && s1.mins == 1)
		ft_pspace(s1.width - 1);
}

void	ft_str(va_list ap, struct s_flags s1)
{
	int		len;
	char	*s;
	char	nu[6];

	len = 0;
	s = va_arg(ap, char*);
	if (!s)
	{
		ft_memcpy(nu, "(null)", 6);
		if (!s1.width && !s1.point && !s1.prec && !s1.isempty)
			ft_putstr_c(nu, 0);
		else
		{
			len = ft_final_len(nu, s1);
			if ((len) > 0 && s1.mins == 0)
				ft_pspace(len);
			if ((s1.point && s1.prec) || (s1.width && !s1.point))
				s1.prec > 0 ? ft_putstr_c(nu, s1.prec) : ft_putstr_c(nu, 0);
			if ((len) > 0 && s1.mins == 1)
				ft_pspace(len);
		}
	}
	else
		ft_print_str(s1, s);
}

void	ft_print_str(struct s_flags s1, char *s)
{
	int len;

	len = 0;
	if (!s1.width && !s1.point)
		ft_putstr_c(s, 0);
	else
	{
		len = ft_final_len(s, s1);
		if ((len) > 0 && !s1.mins)
			ft_pspace(len);
		if ((s1.point && s1.prec) || (s1.width && !s1.point))
			s1.prec > 0 ? ft_putstr_c(s, s1.prec) : ft_putstr_c(s, 0);
		if ((len) > 0 && s1.mins)
			ft_pspace(len);
	}
}
