/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:14:37 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/05 11:08:34 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void **))
{
	if (!alst || !alst)
		return ;
	if (del)
		del(&(*alst)->data);
	if ((*alst)->data)
		ft_memdel(&(*alst)->data);
	free(*alst);
	*alst = NULL;
}
