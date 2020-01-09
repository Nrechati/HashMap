/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:30:26 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/07 15:37:43 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char *p_s1;
	const unsigned char *p_s2;

	p_s1 = s1;
	p_s2 = s2;
	while (len > 0)
	{
		if (*p_s1 != *p_s2)
			return (*p_s1 - *p_s2);
		else
		{
			p_s1++;
			p_s2++;
		}
		len--;
	}
	return (0);
}
