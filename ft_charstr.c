/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:29:34 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/05 18:39:17 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
void	ft_charstr(char s, va_list ap)
{
	if (s == 'c')
		ft_putstr_c(c_toa(va_arg(ap, int)));
	else
		ft_putstr_c(va_arg(ap, char *));
}
