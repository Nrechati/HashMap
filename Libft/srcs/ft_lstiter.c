/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:43:11 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/09 13:43:12 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*ptr_lst;

	ptr_lst = lst;
	while (ptr_lst != NULL)
	{
		f(ptr_lst);
		ptr_lst = ptr_lst->next;
	}
}
