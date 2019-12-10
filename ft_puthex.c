/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:51 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/10 18:22:52 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(va_list ap, char sep)
{
	if (sep == 'x')
		ft_putstr_c(ft_hex(va_arg(ap, unsigned int), 0, 0), 0);
	else if (sep == 'X') 
		ft_putstr_c(ft_hex(va_arg(ap, unsigned int), 32, 0), 0);
	else
		ft_putstr_c(ft_hex(va_arg(ap, unsigned long), 0, 1), 0);
			
}
