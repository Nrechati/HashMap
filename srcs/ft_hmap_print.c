/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:03:12 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/26 12:04:00 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

void	ft_print_hashmap(t_hash *hashmap)
{
	size_t		i;
	t_list		*ptr;

	i = 0;
	ft_printf("\n		. . . Printing . . .\n\n");
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
