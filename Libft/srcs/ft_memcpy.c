/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:30:34 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/07 15:38:33 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char			*p_dst;
	const char		*p_src;

	p_dst = dst;
	p_src = src;
	while (len > 0)
	{
		*p_dst = *p_src;
		p_dst++;
		p_src++;
		len--;
	}
	return (dst);
}
