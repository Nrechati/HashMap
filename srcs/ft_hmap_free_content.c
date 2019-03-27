/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_free_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:31:34 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/27 17:14:41 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

void	ft_hmap_free_content(t_hash *hashmap, void (*del)(void *))
{
	size_t	i;
	t_list	*ptr;
	t_list	*tmp;
	t_hnode	*node;

	i = 0;
	while (i < hashmap->map_size)
	{
		ptr = hashmap->map[i];
		if (ptr)
		{
			while (ptr != NULL)
			{
				tmp = ptr;
				ptr = ptr->next;
				tmp->next = NULL;
				node = (t_hnode *)tmp->data;
				ft_del_hnode(node, del);
				free(tmp);
			}
		}
		i++;
	}
	free(hashmap->map);
	hashmap->map = NULL;
}
