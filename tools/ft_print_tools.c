/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:45:08 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/28 03:11:18 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_count++;
}

int		ft_putstr_c(char *str, int index)
{
	int i;

	i = 0;
	if (!index)
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
			g_count++;
		}
	}
	if (index)
	{
		while (i < index && str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
			g_count++;
		}
	}
	return (i);
}

void	ft_pspace(int value)
{
	int i;

	i = 0;
	while (value > 0)
	{
		write(1, " ", 1);
		i++;
		g_count++;
		value--;
	}
}

void	ft_pzero(int value)
{
	while (value > 0)
	{
		write(1, "0", 1);
		g_count++;
		value--;
	}
}
