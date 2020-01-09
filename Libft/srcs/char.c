/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:36:59 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/05 11:09:20 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	character(t_format *format)
{
	char		*tmp;
	char		*width;

	width = NULL;
	tmp = ft_strnew(1);
	*tmp = format->arg.character;
	format->width = format->width - 1;
	if (format->width > 0)
	{
		width = ft_strnew(format->width);
		if (format->flag_zero && !format->flag_minus)
			ft_memset(width, '0', format->width);
		else
			ft_memset(width, ' ', format->width);
	}
	if (format->flag_minus)
		format->output = ft_strjoin(tmp, width);
	else
		format->output = ft_strjoin(width, tmp);
	ft_strdel(&tmp);
	ft_strdel(&width);
	return ;
}
