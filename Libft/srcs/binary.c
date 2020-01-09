/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 22:11:53 by cempassi          #+#    #+#             */
/*   Updated: 2019/02/18 12:05:48 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	binary(t_format *format)
{
	char	*tmp;
	char	*holder;
	int		len;

	tmp = unsigned_convert(format);
	holder = tmp;
	tmp = *holder ? ft_convert_base(tmp, TEN, BINARY) : tmp;
	if (*holder)
		ft_strdel(&holder);
	len = ft_strlen(tmp);
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	if (format->flag_hashtag)
	{
		holder = tmp;
		tmp = ft_strjoin("0b", tmp);
		ft_strdel(&holder);
	}
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	format->output = tmp;
	return ;
}
