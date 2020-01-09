/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:30:00 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/07 15:35:52 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	while (len > 0)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		dst++;
		if (*(unsigned char*)src == (unsigned char)c)
			return (dst);
		src++;
		len--;
	}
	return (NULL);
}
