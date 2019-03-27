/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:03:12 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/27 15:00:19 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

void	ft_print_hashmap(t_hash *hashmap)
{
	size_t		i;
	size_t		fill;
	t_list		*ptr;

	i = 0;
	fill = ft_hmap_filled_norm(hashmap);
	if (fill < 20 || fill >= 70)
		ft_printf("\n\x1b[31mMap size : %zu  ||  . . . Printing . . .  ||  Filled at %zu%%\x1b[0m\n\n", hashmap->map_size, fill);
	else
		ft_printf("\n\x1b[32mMap size : %zu  ||  . . . Printing . . .  ||  Filled at %zu%%\x1b[0m\n\n", hashmap->map_size, fill);
	while (i < hashmap->map_size)
	{
		if (hashmap->map[i] != NULL)
		{
			ft_printf("| %zu | :", i);
			ptr = hashmap->map[i];
			while (ptr != NULL)
			{
				ft_printf(" | Key = %s -> Data = %s | -"
				, ((t_hnode*)ptr->data)->key, ((t_hnode*)ptr->data)->data);
				ptr = ptr->next;
			}
			ft_printf(" NULL\n");
		}
		i++;
	}
}