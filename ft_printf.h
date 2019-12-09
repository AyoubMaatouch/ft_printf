/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:41:33 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/09 18:23:11 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

struct	flags {
	int width;
	va_list ap;
	int i;
	int mins;
};

int		ft_atoi(const char *str);
int		ft_isdigit(int str);
int		ft_printf(const char *format, ...);
int		ft_putstr_c(char *str);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
char	*c_toa(char c);
char	*ft_hex(unsigned long nb, int maj, int p);
void	ft_conv(const char *format, struct flags s1);
void	ft_charstr(va_list ap, struct flags s1, char format);
void	ft_putdigit(va_list ap, char sep);
void	ft_puthex(va_list ap, char sep);
int		ft_strlen(char *str);

struct flags ft_flag(char *format, struct flags s1);
