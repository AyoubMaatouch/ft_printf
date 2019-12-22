/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:10:42 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/22 21:48:27 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_char(va_list ap, struct s_flags s1)
{
	if (s1.width > 1 && s1.mins == 0)
		ft_pspace(s1.width - 1);
	//ft_putstr_c(c_toa(va_arg(ap, int)), s1.prec);
	ft_putchar(va_arg(ap, int));
	if (s1.width > 1 && s1.mins == 1)
		ft_pspace(s1.width - 1);
}

void	ft_str(va_list ap, struct s_flags s1)
{

	int len;
	char *s;

	len = 0;
	s = va_arg(ap, char*);
	if (!s)
	{
		if (!s1.width && s1.prec == -1 && !s1.isempty)
			ft_putstr_c("(null)", 0);
		else
		{	
		len = ft_final_len("(null)", s1);
	if ((len) > 0 && s1.mins == 0)
		ft_pspace(len);
	ft_putstr_c("(null)", s1.prec);
	if ((len) > 0 && s1.mins == 1)
		ft_pspace(len);
	}
	}
	else
	{
				if (!s1.width && s1.prec == -1 &&!s1.isempty)
			ft_putstr_c(s, 0);
		else
{
	len = ft_final_len(s, s1);
	if ((len) > 0 && s1.mins == 0)
		ft_pspace(len);
	ft_putstr_c(s, s1.prec);
	if ((len) > 0 && s1.mins == 1)
		ft_pspace(len);
	}
	 }
}