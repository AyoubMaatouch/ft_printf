/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:10:42 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/13 15:36:03 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_char(va_list ap, struct s_flags s1)
{
	if (s1.width > 1 && s1.mins == 0)
		ft_pspace(s1.width - 1);
	ft_putstr_c(c_toa(va_arg(ap, int)), s1.prec);
	if (s1.width > 1 && s1.mins == 1)
		ft_pspace(s1.width - 1);
}

void	ft_str(va_list ap, struct s_flags s1)
{

	int len;
	char *s;

	len = 0;
	s = va_arg(ap, char*);
	len = ft_final_len(s, s1);
	if ((len) > 1 && s1.mins == 0)
		ft_pspace(len);
	ft_putstr_c(s, s1.prec);
	if ((len) > 1 && s1.mins == 1)
		ft_pspace(len);
}