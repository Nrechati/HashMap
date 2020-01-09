/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:46:13 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/28 12:26:16 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *holder;

	if (*alst == NULL)
		*alst = new;
	else
	{
		holder = *alst;
		while (holder->next != NULL)
			holder = holder->next;
		holder->next = new;
	}
	return (1);
}
