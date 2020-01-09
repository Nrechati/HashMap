/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:46:23 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/07 11:14:56 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *alst)
{
	int		length;
	t_list	*ptr_list;

	if (alst == NULL)
		return (0);
	length = 0;
	ptr_list = alst;
	while (ptr_list->next != NULL)
	{
		length++;
		ptr_list = ptr_list->next;
	}
	return (length + 1);
}
