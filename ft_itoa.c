/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:14:35 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/02 15:38:09 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_alloc(unsigned int nb, int nbr)
{
	int i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	if (nbr <= 0)
		i++;
	return (i);
}

static void		ft_putnbr(unsigned int nb, char *nbr_r, unsigned int num_alloc)
{
	while (nb > 9)
	{
		nbr_r[num_alloc] = nb % 10 + 48;
		nb /= 10;
		num_alloc--;
	}
	nbr_r[num_alloc] = nb % 10 + 48;
}




char			*ft_itoa(int n)
{
	unsigned int	n_nbr;
	int				num_alloc;
	char			*nbr_r;

	if (n < 0)
		n_nbr = n * -1;
	else
		n_nbr = n;
	num_alloc = ft_alloc(n_nbr, n);
	if (!(nbr_r = (char*)malloc(num_alloc * sizeof(char) + 1)))
		return (NULL);
	if (n < 0)
		nbr_r[0] = '-';
	ft_putnbr(n_nbr, nbr_r, num_alloc - 1);
	nbr_r[num_alloc] = 0;
	return (nbr_r);
}

char			*ft_itoa_u(unsigned int n)
{
	unsigned int	n_nbr;
	unsigned int		num_alloc;
	char			*nbr_r;

	n_nbr = n;
	num_alloc = ft_alloc(n, 1);
	if (!(nbr_r = (char*)malloc(num_alloc * sizeof(char) + 1)))
		return (NULL);
	ft_putnbr(n_nbr, nbr_r, num_alloc - 1);
	nbr_r[num_alloc] = 0;
	return (nbr_r);
}
