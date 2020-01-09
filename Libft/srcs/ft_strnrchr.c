/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:21:28 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/22 18:18:18 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnrchr(const char *s, char c)
{
	int i;

	i = ft_strlen(s) - 1;
	if (c == '\0')
		return (i);
	while (s[i] && s[i] != c)
		i--;
	return (i + 1);
}
