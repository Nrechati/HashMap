/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:08:36 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/26 12:01:47 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

void		del_hash_str(void *data)
{
	free(data);
}

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
		ft_printf("Adding %s Key with %s Data\n", av[i], av[i + 1]);
		ft_hash_insert(&hashmap, av[i], data);
		i += 2;
	}
	ft_print_hashmap(&hashmap);
//	ft_hash_remove(&hashmap, "ls", del_hnode);
//	ft_hash_remove(&hashmap, "echo", del_hnode);
//	ft_hash_remove(&hashmap, "cd", del_hnode);
//	print_hashmap(&hashmap);
//	free(hashmap);
	return (0);
}
