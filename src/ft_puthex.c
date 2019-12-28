/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:51 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/28 04:28:33 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_x(va_list ap, struct s_flags s1)
{
	int				len;
	struct s_hex	h1;

	h1.zero = 0;
	h1.space = 0;
	h1.value = va_arg(ap, unsigned int);
	h1.hex = ft_hex(h1.value, 0, 0);
	len = ft_strlen(h1.hex);
	if (s1.point && (s1.zero || s1.prec) && s1.prec > 0)
		h1.zero = s1.prec - len;
	if (s1.width)
	{
		if (h1.zero > 0)
			h1.space = s1.width - (h1.zero + len);
		else if (!h1.zero && (!s1.point || s1.prec < 0) && s1.zero && !s1.mins)
			h1.zero = s1.width - len;
		else
			h1.space = s1.width - len;
	}
	ft_output_xx(s1, h1);
}

void	ft_put_xx(va_list ap, struct s_flags s1)
{
	int				len;
	struct s_hex	h1;

	h1.zero = 0;
	h1.space = 0;
	h1.value = va_arg(ap, unsigned int);
	h1.hex = ft_hex(h1.value, 32, 0);
	len = ft_strlen(h1.hex);
	if (s1.point && (s1.zero || s1.prec) && s1.prec > 0)
		h1.zero = s1.prec - len;
	if (s1.width)
	{
		if (h1.zero > 0)
			h1.space = s1.width - (h1.zero + len);
		else if (!h1.zero && (!s1.point || s1.prec < 0) && s1.zero && !s1.mins)
			h1.zero = s1.width - len;
		else
			h1.space = s1.width - len;
	}
	ft_output_xx(s1, h1);
}

void	ft_output_xx(struct s_flags s1, struct s_hex h1)
{
	if (h1.space && !s1.mins)
		ft_pspace(h1.space);
	if (h1.zero)
		ft_pzero(h1.zero);
	if (s1.point && s1.prec == 0 && h1.value == 0)
		s1.width ? ft_putchar(' ') : 0;
	else
		ft_putstr_c(h1.hex, 0);
	if (h1.space && s1.mins)
		ft_pspace(h1.space);
}

void	ft_put_p(va_list ap, struct s_flags s1)
{
	struct s_hex	h1;
	int				len;

	h1.zero = 0;
	h1.space = 0;
	h1.value = va_arg(ap, unsigned long);
	h1.hex = ft_hex(h1.value, 0, 1);
	len = ft_strlen(h1.hex);
	if (s1.point && (s1.zero || s1.prec) && s1.prec > 0)
		h1.zero = s1.prec - len;
	if (s1.width)
	{
		if (h1.zero > 0)
			h1.space = s1.width - (h1.zero + len);
		else if (!h1.zero && (!s1.point || s1.prec < 0) && s1.zero && !s1.mins)
			h1.zero = s1.width - len;
		else
			h1.space = (!h1.value && (!s1.width || (s1.point && !s1.prec))) ?
				s1.width - len + 1 : s1.width - len;
	}
	ft_output_p(s1, h1);
}

void	ft_output_p(struct s_flags s1, struct s_hex h1)
{
	if (h1.space && !s1.mins)
		ft_pspace(h1.space);
	if (h1.zero)
		ft_pzero(h1.zero);
	if (s1.point && s1.prec == 0 && h1.value == 0)
		ft_putstr_c("0x", 0);
	else
		ft_putstr_c(h1.hex, 0);
	if (h1.space && s1.mins)
		ft_pspace(h1.space);
}
