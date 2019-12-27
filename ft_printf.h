/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:41:33 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/26 20:19:01 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

struct	s_flags {
	int width;
	va_list ap;
	int i;
	int mins;
	int point;
	int prec;
	int zero;
	int isempty;
	int zeroPrinted;
};
int		g_count;
int		ft_printf(const char *format, ...);
int		ft_atoi(const char *str);
int		ft_isdigit(int str);
int		ft_printf(const char *format, ...);
int		ft_putstr_c(char *str, int index);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
char	*c_toa(char c);
char	*ft_hex(unsigned long nb, int maj, int p);
void	ft_conv(const char *format, struct s_flags s1);
void	ft_char(va_list ap, struct s_flags s1);
void	ft_str(va_list ap, struct s_flags s1);
void	ft_putdigit(va_list ap, struct s_flags s1, char sep);
void	ft_puthex(va_list ap, char sep, struct s_flags s1);
int		ft_strlen(char *str);
int		ft_pzero(int value);
int		ft_pspace(int value);
struct	s_flags ft_flag(char *format, struct s_flags s1, va_list ap);
int		ft_final_len(char *s, struct s_flags s1);
int		ft_putchar(char c);
int 	ft_putstr_d(char *str, int index);
void	ft_putdigit_u(va_list ap, struct s_flags s1);
int		ft_putstr_s(char *str, int index, int width);
int 	ft_is_flag(char c);
void	ft_p(struct s_flags s1);