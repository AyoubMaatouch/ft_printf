/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:17:36 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/11 14:31:56 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_final_len(char *s, struct s_flags s1)
{
	int len;

	len = 0;
	if (s1.prec && s1.prec < ft_strlen(s))
	{
		len = s1.width - s1.prec;
	}	
	else
		len = s1.width - ft_strlen(s);
	return (len);
}
