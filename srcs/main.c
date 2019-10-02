/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:08:36 by nrechati          #+#    #+#             */
/*   Updated: 2019/10/02 12:37:43 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

int			main(int ac, char **av)
{
	int		i;
	void	*data;
	t_hash	hashmap;

	i = 1;
	hashmap = ft_hmap_init(2048);
	if (!hashmap.map)
		return (0);
	if (ac < 2)
		return (0);
	while (av[i] != NULL)
	{
		data = ft_strdup(av[i + 1]);
		if (!data)
			break ;
		if (!ft_hmap_insert(&hashmap, (av[i]), data))
			free(data);
		i += 2;
	}
	if (!ft_hmap_remove(&hashmap, "md5", free))
		free(data);
	ft_print_hashmap(&hashmap);
	ft_printf("\n\n\x1b[32m SUMMARY || Final Map Size = %zu || Filled at %zu%% || Number of collisions = %zu || Collision Rate = %zu%%\x1b[0m\n"
		, hashmap.map_size, ft_hmap_filled_norm(&hashmap)
		, ft_hmap_collision(&hashmap), ft_hmap_collision_rate(&hashmap));
	ft_hmap_free_content(&hashmap, free);
	return (0);
}
