/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:38:54 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/12 12:38:56 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_base_check_and_strlen(char *str)
{
	int		i;
	int		length;

	length = 0;
	while (str[length])\
	{
		if (str[length] == '-' || str[length] == '+')
			return (0);
		i = length;
		while (i-- >= 0)
			if (str[i] == str[length])
				return (0);
		length++;
	}
	return (length);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int		nbase;

	nbase = ft_base_check_and_strlen(base);
	if (nbase > 1)
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			ft_putnbr_base(-1 * (nbr / nbase), base);
			ft_putchar(base[-1 * (nbr % nbase)]);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
			ft_putnbr_base(nbr, base);
		}
		else if (nbr >= nbase)
		{
			ft_putnbr_base(nbr / nbase, base);
			ft_putnbr_base(nbr % nbase, base);
		}
		else
			ft_putchar(base[nbr]);
	}
}
