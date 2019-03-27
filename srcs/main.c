/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:08:36 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/27 18:23:25 by nrechati         ###   ########.fr       */
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
	hashmap = ft_init_hashmap(2048);
	if (!hashmap.map)
		return (0);
	if (ac < 2)
		return (0);
	while (av[i] != NULL)
	{
		data = ft_strdup(av[i + 1]);
		if (!data)
			break;
		if (!ft_hmap_insert(&hashmap, (av[i]), data))
			free(data);
		i += 2;
	}
	ft_print_hashmap(&hashmap);
	ft_printf("\n\n\x1b[32m SUMMARY || Final Map Size = %zu || Filled at %zu%% || Number of collisions = %zu || Collision Rate = %zu%%\x1b[0m\n"
		, hashmap.map_size, ft_hmap_filled_norm(&hashmap)
		, ft_hmap_collision(&hashmap), ft_hmap_collision_rate(&hashmap));
	ft_hmap_free_content(&hashmap, free);
	return (0);
}

/*
void	*hash(t_registre *hashmap)
if (hashmap->map != NULL)
	free_content(hashmap.map);
	free(hasmap.map)
tab = split(PATH)
open tab[i]
	while (ret = read tab[i])
		if (access(ret) & X_OK)
			insert ("cd", asptin(tab[i]/ret)
	closdir ret;
	i++;



 execve(ft_hmap_getdata(cmd));
*/
