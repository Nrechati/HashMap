/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:46:45 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/27 14:25:29 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_chgnext(size_t i, t_list *ptr_lst, t_list **alst)
{
	size_t		j;

	while (i >= 1)
	{
		ptr_lst = *alst;
		j = 1;
		while (j < i - 1)
		{
			ptr_lst = ptr_lst->next;
			j++;
		}
		ptr_lst->next->next = ptr_lst;
		ptr_lst = *alst;
		i--;
	}
	return (ptr_lst);
}

void			ft_lstrev(t_list **alst)
{
	size_t		i;
	size_t		node_nbr;
	t_list		*ptr_lst;
	t_list		*new_head;

	if (*alst == NULL)
		return ;
	node_nbr = 1;
	ptr_lst = *alst;
	if (ptr_lst->next == NULL)
		return ;
	while (ptr_lst->next != NULL)
	{
		node_nbr++;
		ptr_lst = ptr_lst->next;
	}
	new_head = ptr_lst;
	i = node_nbr;
	ptr_lst = ft_chgnext(i, ptr_lst, alst);
	ptr_lst->next = NULL;
	*alst = new_head;
}
