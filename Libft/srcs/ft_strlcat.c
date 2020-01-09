/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:26:25 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/05 17:10:59 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int				i;
	int				j;
	int				len;
	unsigned int	n;

	n = size;
	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	while (n-- != 0 && dst[i] != '\0')
		i++;
	n = size - i;
	if (!n)
		return (size + ft_strlen(src));
	while (src[j] && n > 0)
	{
		if (n > 1)
			dst[i++] = src[j++];
		n--;
	}
	dst[i] = '\0';
	return (len);
}
