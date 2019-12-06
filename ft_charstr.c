/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:22:25 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/06 18:06:12 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_charstr(struct flags s1, char format)
{
	if (format == 'c')
		ft_putstr_c(c_toa(va_arg(s1.ap, int)));
	else
		ft_putstr_c(va_arg(s1.ap, char*));
	
}
