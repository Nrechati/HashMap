/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:04:08 by achavy            #+#    #+#             */
/*   Updated: 2019/03/07 11:22:24 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		**ft_int_2d(int it, int jt)
{
	int	i;
	int	**tab;

	i = 0;
	tab = (int**)malloc(sizeof(int*) * (it + 1));
	if (!tab)
		return (NULL);
	while (i < it)
	{
		tab[i] = (int*)ft_memalloc(sizeof(int) * (jt + 1));
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
