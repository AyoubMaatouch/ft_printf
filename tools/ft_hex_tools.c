/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:48:31 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/28 17:54:16 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int i;

	i = 0;
	if (dest == src)
		return (dest);
	if ((dest) == 0 && (src) == 0)
		return (NULL);
	while (n > i)
	{
		((char*)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_rev(char *str, int p)
{
	int		i;
	int		j;
	char	*rev;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	if (!(rev = malloc(sizeof(char) * i + 3)))
		return (ft_error_check(NULL));
	if (p)
	{
		rev[j++] = '0';
		rev[j++] = 'x';
	}
	while (i--)
		rev[j++] = str[i];
	rev[j] = '\0';
	return (rev);
}

char	*ft_hex(unsigned long nb, int maj, int p)
{
	char	ret[21];
	char	hex[16];
	int		i;

	i = 0;
	ft_memcpy(hex, "0123456789abcdef", 16);
	while (nb >= 16)
	{
		if ((nb % 16) > 9 && maj == 32)
			ret[i] = hex[nb % 16] - 32;
		else
			ret[i] = hex[nb % 16];
		nb /= 16;
		i++;
	}
	if (maj == 32 && nb > 9)
		ret[i] = hex[nb] - 32;
	else
		ret[i] = hex[nb];
	ret[++i] = '\0';
	return (ft_rev(ret, p));
}
