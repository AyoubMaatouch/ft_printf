/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:49:51 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/16 14:30:05 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_puthex(va_list ap, char sep, struct s_flags s1)
{
	char *hex;
	int len;

	if (sep == 'x')
		ft_putstr_c(ft_hex(va_arg(ap, unsigned int), 0, 0), 0);
	else if (sep == 'X') 
		ft_putstr_c(ft_hex(va_arg(ap, unsigned long), 32, 0), 0);
	else
	{	
	hex = ft_hex(va_arg(ap, unsigned long), 0, 1);
	len = ft_final_len(hex, s1);
	if ((len) > 0 && s1.mins == 0)
		ft_pspace(len);
	//here
			ft_putstr_c(hex , 0);

	if ((len) > 0 && s1.mins == 1)
		ft_pspace(len);
	}		
}