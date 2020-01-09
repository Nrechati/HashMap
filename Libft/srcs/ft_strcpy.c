/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:26:12 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/05 15:50:25 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *d;

	if (!src)
		return (dst);
	d = dst;
	while (*src)
		*d++ = *src++;
	*d = '\0';
	return (dst);
}
