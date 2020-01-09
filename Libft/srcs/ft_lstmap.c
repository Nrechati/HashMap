/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:58:31 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/09 13:58:32 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ptr_lst;
	t_list		*ptr_newlst;
	t_list		*new_head;
	t_list		*new;

	ptr_lst = lst;
	if (!lst)
		return (NULL);
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new = f(ptr_lst);
	ptr_lst = ptr_lst->next;
	new_head = new;
	ptr_newlst = new;
	while (ptr_lst != NULL)
	{
		if (!(new = malloc(sizeof(t_list))))
			return (NULL);
		new = f(ptr_lst);
		ptr_newlst->next = new;
		ptr_newlst = ptr_newlst->next;
		ptr_lst = ptr_lst->next;
	}
	ptr_newlst->next = NULL;
	return (new_head);
}
