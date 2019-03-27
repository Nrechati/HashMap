/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:08:36 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/27 11:31:45 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"
#include "stdio.h"

int			main(int ac, char **av)
{
	int		i;
	void	*data;
	t_hash	hashmap;

	i = 1;
	hashmap = ft_init_hashmap();
	if (!hashmap.map)
	{
		return (0);
	}
	if (ac < 2)
		return (0);
	while (av[i] != NULL)
	{
		data = ft_strdup(av[i + 1]);
		if (!data)
			return (0);

		if (ft_hash_insert(&hashmap, av[i], data))
		{
			ft_printf("Adding %s Key with %s Data\n", av[i], av[i + 1]);
			ft_printf("Used = %zu || Filled at %zu %% || RAW = %zu\n"
				, hashmap.used, ft_hmap_filled_norm(&hashmap), ft_hmap_filled(&hashmap));
		}
		i += 2;
	}
	ft_print_hashmap(&hashmap);
	//	ft_hash_remove(&hashmap, "echo", free);
	//	ft_hash_remove(&hashmap, "cd", free);
	//	print_hashmap(&hashmap);
	//	free(hashmap);
	return (0);
}

/*
void	*hash(t_registre *hashmap)
if (hashmap->map != NULL)
	free(hasmap->map)
tab = split(PATH)
open tab[i]
	while (ret = read tab[i])
		if (access(ret) & X_OK)
			insert (ret, tab[i]/ret)
	closdir ret;
	i++;

 execve(ft_hmap_getdata(cmd));
*/
