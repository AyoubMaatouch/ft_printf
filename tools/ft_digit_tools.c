/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:46:46 by aymaatou          #+#    #+#             */
/*   Updated: 2019/12/28 17:53:58 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_isdigit(int str)
{
	if (str >= 48 && str <= 57)
		return (1);
	return (0);
}

unsigned int	ft_alloc(unsigned int nb, int nbr)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		i++;
		nb /= 10;
	}
	if (nbr == 0)
		i++;
	return (i);
}

void			ft_putnbr(unsigned int nb, char *nbr_r, unsigned int num_alloc)
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
		return (ft_error_check(NULL));
	if (n < 0)
		nbr_r[0] = '\0';
	ft_putnbr(n_nbr, nbr_r, num_alloc - 1);
	nbr_r[num_alloc] = 0;
	return (nbr_r);
}

char			*ft_itoa_u(unsigned int n)
{
	unsigned int	n_nbr;
	unsigned int	num_alloc;
	char			*nbr_r;

	n_nbr = n;
	num_alloc = ft_alloc(n, 1);
	if (!(nbr_r = (char*)malloc(num_alloc * sizeof(char) + 1)))
		return (ft_error_check(NULL));
	ft_putnbr(n_nbr, nbr_r, num_alloc - 1);
	nbr_r[num_alloc] = 0;
	return (nbr_r);
}
