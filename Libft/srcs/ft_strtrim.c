/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:01:19 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/08 16:01:21 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int				i;
	unsigned int	start;
	int				len;
	char			*dst;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	start = i;
	if (i == (int)ft_strlen(s))
		return (ft_strnew(1));
	len = 0;
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	if (!(dst = (char *)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	dst = ft_strsub(s, start, len - i + 1);
	return (dst);
}
