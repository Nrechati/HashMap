/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:07:32 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/21 17:27:03 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
#define HASHMAP_H
#include <stdlib.h>
#include <stdint.h>

typedef struct	s_hash
{
	int		map_size;
	int		used;
	t_list	**map;
}				t_hash;

typedef struct	s_hnode
{
	char	*key;
	void	*data;
}				t_hnode;

uint32_t	ft_hash_str(char *key);
int			ft_norm_hash(uint32_t hash, int tab_size);

#endif
