/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:26:34 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/05 16:59:56 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_list	*eraser(t_list *current, void (*del)(void **))
{
	if (current)
	{
		eraser(current->next, del);
		ft_lstdelone(&current, del);
	}
	return (NULL);
}

void			*ft_lstdel(t_list **alst, void (*del)(void **))
{
	if (!alst || !*alst)
		return (NULL);
	*alst = eraser(*alst, del);
	return (NULL);
}
