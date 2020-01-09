/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:27:05 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/07 15:44:49 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	char		*h_char;
	char		*n_char;

	if (!*needle)
		return ((char *)haystack);
	while (len-- && *haystack)
	{
		if (*haystack == *needle)
		{
			i = len;
			h_char = (char *)haystack + 1;
			n_char = (char *)needle + 1;
			while (i-- && *h_char && *n_char && *h_char == *n_char)
			{
				++h_char;
				++n_char;
			}
			if (!*n_char)
				return ((char *)haystack);
		}
		++haystack;
	}
	return (NULL);
}
