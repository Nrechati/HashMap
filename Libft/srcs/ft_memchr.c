/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:30:06 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/07 15:36:54 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char *p_str;

	p_str = (unsigned char*)str;
	while (len > 0)
	{
		if (*p_str != (unsigned char)c)
			p_str++;
		else
			return (p_str);
		len--;
	}
	return (0);
}
