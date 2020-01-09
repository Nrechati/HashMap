/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:30:40 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/12 10:53:00 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!len)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
		while (--len > 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return (dst);
}
