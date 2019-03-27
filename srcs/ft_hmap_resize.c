/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:18:15 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/27 11:30:50 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

size_t		ft_get_two_pw(size_t nb)
{
	size_t i;

	i = 0;
	while (nb != 1)
	{
		nb >>= 1;
		i++;
	}
	return (i);
}

size_t		ft_hmap_filled(t_hash *hashmap)
{
	return ((hashmap->used << 7) >> ft_get_two_pw(hashmap->map_size));
}

size_t		ft_hmap_filled_norm(t_hash *hashmap)
{
	return ((ft_hmap_filled(hashmap) * 100) >> 7);
}

/*
int			ft_hmap_resize(t_hash *hashmap)
{

	return(1);
}
*/
