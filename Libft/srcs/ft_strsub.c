/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:15:00 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/08 15:15:02 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			count;
	char			*dst;

	i = start;
	if (s == NULL)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	count = 0;
	while (count < len)
	{
		dst[count] = s[i];
		count++;
		i++;
	}
	dst[count] = '\0';
	return (dst);
}
