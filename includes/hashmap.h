/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:07:32 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/27 11:26:51 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H
# include <stdlib.h>
# define MAP_SIZE 64

typedef struct	s_hash
{
	size_t		map_size;
	size_t		used;
	t_list		**map;
}				t_hash;

typedef struct	s_hnode
{
	char		*key;
	void		*data;
}				t_hnode;

uint32_t		ft_hash_str(char *key, size_t tab_size);
t_hash			ft_init_hashmap(void);
void			ft_print_hashmap(t_hash *hashmap);
void			*ft_hmap_getdata(t_hash *hashmap, char *key);
int				ft_hash_remove(t_hash *hashmap, char *key, void (*del)(void *));
int				ft_hash_insert(t_hash *hashmap, char *key, void *data);
size_t			ft_hmap_filled(t_hash *hashmap);
size_t			ft_hmap_filled_norm(t_hash *hashmap);
size_t			ft_get_two_pw(size_t nb);

#endif
