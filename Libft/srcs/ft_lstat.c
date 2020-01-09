/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:47:07 by nrechati          #+#    #+#             */
/*   Updated: 2018/11/09 16:47:08 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstat(t_list *alst, unsigned int n)
{
	unsigned int	i;
	t_list			*ptr_lst;

	if (alst == NULL)
		return (NULL);
	i = 0;
	ptr_lst = alst;
	if (!alst || n == 0)
		return (NULL);
	if (ptr_lst->next == NULL && i < n)
	{
		ptr_lst = NULL;
		return (ptr_lst);
	}
	while (i < n)
	{
		ptr_lst = ptr_lst->next;
		i++;
	}
	return (ptr_lst);
}
