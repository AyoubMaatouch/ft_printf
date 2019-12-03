/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:41:33 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/03 18:26:43 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putstr_c(char *str);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
char	*c_toa(char c);
char	*ft_hex(unsigned long nb, int maj, int p);
