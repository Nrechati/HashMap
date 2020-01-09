/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 09:45:19 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/05 11:09:20 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	string(t_format *format)
{
	char	*tmp;
	char	*width;

	width = NULL;
	if (format->precision == -1)
		tmp = ft_strdup(format->arg.string);
	else
		tmp = ft_strsub(format->arg.string, 0, format->precision);
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
	{
		width = ft_strnew(format->width);
		if (format->flag_zero && !format->flag_minus)
			ft_memset(width, '0', format->width);
		else
			ft_memset(width, ' ', format->width);
	}
	format->output = format->flag_minus ? ft_strjoin(tmp, width)
										: ft_strjoin(width, tmp);
	ft_strdel(&tmp);
	ft_strdel(&width);
	return ;
}
