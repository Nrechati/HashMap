/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:08:36 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/21 17:25:18 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"
#include <stdio.h>
#define MAP_SIZE 124

void	del_hnode(t_list	*node)
{
	free(((t_hnode*)node->data)->key);
	((t_hnode*)node->data)->key = NULL;
	free(((t_hnode *)node->data)->data);
	((t_hnode *)node->data)->data = NULL;
	free(node->data);
	free(node);
}

int		create_hnode(t_list **alst, char *key, void *data)
{
	t_hnode h_node;
	t_list *newdir;

	if (key == NULL)
		return (0);
	ft_bzero(&h_node, sizeof(t_hnode));
	h_node.key = ft_strdup(key);
	h_node.data = data;
	if (h_node.key == NULL || h_node.data == NULL)
		return (0);
	if (!(newdir = ft_lstnew(&h_node, sizeof(t_hnode))))
		return (0);
	ft_lstaddend(alst, newdir);
	return (1);
}

t_hash	ft_init_hashmap(void)
{
	t_hash data;

	data.used = 0;
	data.map = ft_memalloc(data.map_size * sizeof(t_list*));
	data.map_size = MAP_SIZE;
	return (data);
}

int		ft_hash_remove(t_hash *hashmap, char *key)
{
	int		hash;
	t_list	*ptr;
	t_list	*tmp;

	hash = ft_norm_hash(ft_hash_str(key), hashmap->map_size);
	ptr = hashmap->map[hash];
	while (ptr->next != NULL)
	{
		if (!ft_strcmp(((t_hnode*)ptr->next->data)->key, key))
		{
			tmp = ptr->next->next;
			del_hnode(ptr->next);
			ptr->next = tmp;
		}
		ptr = ptr->next;
	}
	return (1);
}

int		ft_hash_insert(t_hash *hashmap, char *key, void *data)
{
	int		hash;

	hash = ft_norm_hash(ft_hash_str(key), hashmap->map_size);
	if (!create_hnode(&hashmap->map[hash], key, data))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int		i;
	t_hash	hashmap;

	i = 1;
	hashmap = ft_init_hashmap();
	if (!hashmap.map)
		return (0);

	if (ac < 2)
		return (0);
	while (av[i])
	{
		printf("%d\n", ft_norm_hash(ft_hash_str(av[i]), hashmap.map_size));
		i++;
	}
	return (0);
}
