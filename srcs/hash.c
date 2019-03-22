/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:05:01 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/22 14:16:17 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

uint32_t	ft_hash_str(char *key)
{
	uint32_t hash;
	uint32_t i;

	i = 0;
	hash = i;
	while (key[i])
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
		i++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}

uint32_t	ft_norm_hash(uint32_t hash, size_t tab_size)
{
	uint32_t n_hash;

	n_hash = hash & (tab_size - 1);
	return (n_hash);
}
