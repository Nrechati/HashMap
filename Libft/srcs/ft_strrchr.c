/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:20:39 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/06 15:20:40 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		ad;

	i = 0;
	ad = -1;
	if (c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)&(s[i]));
	}
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ad = i;
		i++;
	}
	if (ad == -1)
		return (NULL);
	else
		return ((char *)&(s[ad]));
}
