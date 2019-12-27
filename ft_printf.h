/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:41:33 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/27 22:05:08 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

struct			s_flags{
	int		width;
	va_list ap;
	int		i;
	int		mins;
	int		point;
	int		prec;
	int		zero;
	int		isempty;
	int		zeroprinted;
};
int				g_count;
int				ft_printf(const char *format, ...);
int				ft_atoi(const char *str);
int				ft_isdigit(int str);
int				ft_printf(const char *format, ...);
int				ft_putstr_c(char *str, int index);
char			*ft_itoa(int n);
char			*ft_itoa_u(unsigned int n);
char			*c_toa(char c);
char			*ft_hex(unsigned long nb, int maj, int p);
void			ft_conv(const char *format, struct s_flags s1);
void			ft_char(va_list ap, struct s_flags s1);
void			ft_str(va_list ap, struct s_flags s1);
void			ft_putdigit(va_list ap, struct s_flags s1, char sep);
void			ft_put_x(va_list ap, struct s_flags s1);
void			ft_put_xx(va_list ap, struct s_flags s1);
void			ft_put_p(va_list ap, struct s_flags s1);
void			ft_send_fo_ft(va_list ap, struct s_flags s1, char c);
int				ft_strlen(char *str);
int				ft_pzero(int value);
int				ft_pspace(int value);
struct s_flags	ft_flag(char *format, struct s_flags s1, va_list ap);
int				ft_final_len(char *s, struct s_flags s1);
void			ft_putchar(char c);
void			ft_putdigit_u(va_list ap, struct s_flags s1);
int				ft_is_flag(char c);
void			ft_p(struct s_flags s1);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_print_str(struct s_flags s1, char *s);

#endif
