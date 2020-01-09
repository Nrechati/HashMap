/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:25:27 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/09 18:36:20 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_putnbr_itoa(long n, char *tmp_tab, int i)
{
	if (n > 0)
	{
		ft_putnbr_itoa(n / 10, tmp_tab, i + 1);
		tmp_tab[i] = (n % 10) + '0';
	}
}

char			*ft_itoa(int n)
{
	int		len;
	int		i;
	char	tmp_tab[12];
	char	*dst;

	i = 0;
	len = 0;
	ft_bzero(tmp_tab, 12);
	if (n == 0)
	{
		dst = ft_strdup("0");
		return (dst);
	}
	if (n < 0)
		tmp_tab[i++] = '-';
	if (i == 0)
		ft_putnbr_itoa((long)n, tmp_tab, i);
	else
		ft_putnbr_itoa(-(long)n, tmp_tab, i);
	ft_strrev(tmp_tab + i);
	dst = ft_strdup(tmp_tab);
	return (dst);
}
