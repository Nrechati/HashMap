/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:26:18 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/05 16:58:56 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*dst;
	size_t		len;
	size_t		i;

	i = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
