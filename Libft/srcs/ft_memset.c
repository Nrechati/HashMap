/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:29:53 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/07 15:39:52 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*p_str;

	p_str = str;
	while (len > 0)
	{
		*p_str = (unsigned char)c;
		p_str++;
		len--;
	}
	return (str);
}
