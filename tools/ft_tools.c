/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:42:37 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/28 17:57:48 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_atoi(const char *str)
{
	long		i;
	long		number;
	int			sign;
	int			l_counter;

	l_counter = 0;
	sign = 1;
	i = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] != '\0')
	{
		if (l_counter > 13 && sign == -1)
			return (0);
		if (l_counter++ > 13 && sign == 1)
			return (-1);
		if (!(str[i] >= 48 && str[i] <= 57))
			return (number * sign);
		number = number * 10 + (str[i++] - 48);
	}
	return (number * sign);
}

int		ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_final_len(char *s, struct s_flags s1)
{
	int len;

	len = 0;
	if (s1.point && s1.prec < 0 && !s1.width)
		len = 0;
	else if (s1.point && s1.prec >= 0 && s1.prec < ft_strlen(s))
		len = s1.width - s1.prec;
	else if (s1.width > ft_strlen(s))
		len = s1.width - ft_strlen(s);
	return (len);
}

char	*c_toa(char c)
{
	char *ret;

	if (!(ret = malloc(sizeof(char) + 1)))
		return (ft_error_check(NULL));
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

void	*ft_error_check(char *str)
{
	g_error = 0;
	if (!str)
		g_error = 1;
	return (0);
}
