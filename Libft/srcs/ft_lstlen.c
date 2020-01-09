/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:45:09 by nrechati          #+#    #+#             */
/*   Updated: 2019/10/02 12:47:18 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstlen(t_list *lst)
{
	size_t		len;

	len = 0;
	if (!lst)
		return (len);
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
