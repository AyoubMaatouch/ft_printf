/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:45:08 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/18 15:56:53 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_putchar(char c)
{	
	write (1, &c, 1);
	g_count++;
	return (0);
}

int ft_putstr_c(char *str, int index)
{
	int i;

	i = 0;
	if (!index) 
	{
		while (str[i] != '\0')
		{
			write (1, &str[i], 1);
			i++;
			g_count++;
		}
	}
	if (index)
	{
		while (i < index &&str[i] != '\0')
		{
			write (1, &str[i], 1);
			i++;
			g_count++;
		}
		write(1, "\0", 1);
	}
	return (i);
}
int ft_putstr_s(char *str, int index, int width)
{
	int i;

	i = 0;
	if ((index == -1 && !width) || !index) 
	{
		while (str[i] != '\0')
		{
			write (1, &str[i], 1);
			i++;
			g_count++;
		}
	}
	if (index)
	{
		while (i < index &&str[i] != '\0')
		{
			write (1, &str[i], 1);
			i++;
			g_count++;
		}
		write(1, "\0", 1);
	}
	return (i);
}
int ft_putstr_d(char *str, int index)
{
	int i;

	i = 0;
	if (index)
	{
		while (i < index &&str[i] != '\0')
		{
			write (1, &str[i], 1);
			i++;
			g_count++;
		}
		write(1, "\0", 1);
	}
	return (i);
}