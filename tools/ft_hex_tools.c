/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:48:31 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/27 21:33:38 by aymaatou         ###   ########.fr       */
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
	rev = malloc(sizeof(char) * i + 3);
	if (p)
	{
		rev[j++] = '0';
		rev[j++] = 'x';
	}
	while (i--)
		rev[j++] = str[i];
	rev[j] = '\0';
	free(str);
	return (rev);
}

char	*ft_hex(unsigned long nb, int maj, int p)
{
	char	*ret;
	char	hex[16];
	int		i;

	i = 0;
	ft_memcpy(hex, "0123456789abcdef", 16);
	ret = malloc(sizeof(char) * 20 + 1);
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
