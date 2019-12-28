/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:38:38 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/28 03:41:06 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putdigit(va_list ap, struct s_flags s1)
{
	int value;
	int len;
	int zero;
	int space;

	space = 0;
	len = 0;
	value = 0;
	zero = 0;
	value = va_arg(ap, int);
	len = ft_strlen(ft_itoa(value));
	if (s1.point && s1.prec && s1.prec > 0 && s1.prec > len)
		zero = s1.prec - len;
	if (s1.width)
	{
		if (zero)
			space = value >= 0 ? s1.width - (zero + len) :
				s1.width - (zero + (len + 1));
		else if (!zero && (!s1.point || s1.prec < 0) && s1.zero && !s1.mins)
			zero = value >= 0 ? s1.width - len : s1.width - (len + 1);
		else
			space = value >= 0 ? s1.width - (len) : s1.width - ((len + 1));
	}
	ft_put_d(s1, space, zero, value);
}

void	ft_put_d(struct s_flags s1, int space, int zero, int value)
{
	if (space > 0 && !s1.mins)
		ft_pspace(space);
	if (value < 0)
		ft_putchar('-');
	if (zero)
		ft_pzero(zero);
	if (s1.point && s1.prec == 0 && value == 0)
		s1.width ? ft_putchar(' ') : 0;
	else
		ft_putstr_c(ft_itoa(value), 0);
	if (space && s1.mins)
		ft_pspace(space);
}

void	ft_putdigit_u(va_list ap, struct s_flags s1)
{
	unsigned int	value;
	int				len;
	int				zero;
	int				space;

	space = 0;
	zero = 0;
	value = va_arg(ap, unsigned int);
	len = ft_strlen(ft_itoa_u(value));
	if (s1.point && (s1.zero || s1.prec) && s1.prec > 0)
		zero = s1.prec - len;
	if (s1.width)
	{
		if (zero > 0)
			space = s1.width - (zero + len);
		else if (!zero && (!s1.point || s1.prec < 0) && s1.zero && !s1.mins)
			zero = s1.width - len;
		else
			space = s1.width - len;
	}
	ft_put_u(s1, space, zero, value);
}

void	ft_put_u(struct s_flags s1, int space, int zero, int value)
{
	if (space && !s1.mins)
		ft_pspace(space);
	if (zero)
		ft_pzero(zero);
	if (s1.point && s1.prec == 0 && value == 0)
		s1.width ? ft_putchar(' ') : 0;
	else
		ft_putstr_c(ft_itoa_u(value), 0);
	if (space && s1.mins)
		ft_pspace(space);
}

void	ft_p(struct s_flags s1)
{
	int len;
	int zero;
	int space;

	len = 1;
	zero = 0;
	space = 0;
	if (s1.zero)
		zero = s1.width - len;
	if (s1.width)
		space = s1.width - len;
	if (zero && !s1.mins)
		ft_pzero(zero);
	else if (space && !s1.mins)
		ft_pspace(space);
	ft_putchar('%');
	if (space && s1.mins)
		ft_pspace(space);
}
