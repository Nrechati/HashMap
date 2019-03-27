/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:05:50 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/26 13:47:54 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

static void		ft_del_hnode(void *node, void (*del)(void *))
{
	free(((t_hnode *)node)->key);
	((t_hnode *)node)->key = NULL;
	if (del)
		del(((t_hnode *)node)->data);
	((t_hnode *)node)->data = NULL;
	free(node);
}

int				ft_hash_remove(t_hash *hashmap, char *key, void (*del)(void *))
{
	uint32_t hash;
	t_list *ptr;
	t_list *tmp;
	t_hnode *data;

	hash = ft_hash_str(key, hashmap->map_size);
	if (!(ptr = hashmap->map[hash]))
		return (0);
	data = ((t_hnode *)hashmap->map[hash]->data);
	if (!ft_strcmp(data->key, key))
	{
		tmp = hashmap->map[hash];
		hashmap->map[hash] = hashmap->map[hash]->next;
		ft_del_hnode(data, del);
		free(tmp);
		if (hashmap->used > 0)
			hashmap->used -= 1;
		return (1);
	}
	while (ptr->next != NULL)
	{
		data = ((t_hnode *)ptr->next->data);
		if (!ft_strcmp(data->key, key))
		{
			tmp = ptr->next->next;
			del(data);
			free(ptr->next);
			ptr->next = tmp;
			if (hashmap->used > 0)
				hashmap->used -= 1;
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}
