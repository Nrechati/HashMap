/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:07:32 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/21 17:52:24 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
#define HASHMAP_H
#include <stdlib.h>
#include <stdint.h>

typedef struct	s_hash
{
	size_t		map_size;
	size_t		used;
	t_list	**map;
}				t_hash;

typedef struct	s_hnode
{
	char	*key;
	void	*data;
}				t_hnode;

uint32_t	ft_hash_str(char *key);
uint32_t	ft_norm_hash(uint32_t hash, size_t tab_size);

#endif
