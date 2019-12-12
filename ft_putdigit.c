/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:38:38 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/12 20:18:33 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdigit(va_list ap, struct s_flags s1,  char sep)
{
	char	*digit;
	int		i;

	if (sep == 'd')
	{
		digit = ft_itoa(va_arg(ap, int));
		if ((i = s1.width - ft_strlen(digit)) > 1 && s1.mins == 0)
		   s1.zero == 0 ? ft_pspace(i) : ft_pzero(i);	
		ft_putstr_c(digit, 0);
		if ((i = s1.width - ft_strlen(digit)) > 1 && s1.mins == 1)
		   ft_pspace(i);	
	}
	else
	{
		digit = ft_itoa_u(va_arg(ap, unsigned int));
		if ((i = s1.width - ft_strlen(digit)) > 1 && s1.mins == 0)
		   ft_pspace(i);	
		ft_putstr_c(digit, 0);
		if ((i = s1.width - ft_strlen(digit)) > 1 && s1.mins == 1)
		   ft_pspace(i);
	}
	if (digit)
		free(digit);	
}
