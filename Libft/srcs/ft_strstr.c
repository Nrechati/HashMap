/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:26:58 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/12 15:15:50 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	if (!*needle)
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (haystack[i])
	{
		while (needle[j] && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char*)(haystack + i));
		j = 0;
		i++;
	}
	return (NULL);
}
