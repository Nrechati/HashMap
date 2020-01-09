/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:02:34 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/08 15:02:35 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	unsigned int	i;
	char			*dst;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
