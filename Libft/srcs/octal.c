/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:47:35 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/05 11:09:20 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	octal(t_format *format)
{
	char	*tmp;
	char	*holder;
	int		len;

	tmp = unsigned_convert(format);
	holder = tmp;
	tmp = *holder ? ft_convert_base(tmp, TEN, OCTAL) : tmp;
	if (*holder)
		ft_strdel(&holder);
	len = ft_strlen(tmp);
	if (format->flag_hashtag)
		if (*tmp != '0')
			format->precision = ft_strlen(tmp) + 1;
	if ((format->precision -= len) > 0)
		tmp = precision(format, tmp);
	format->width = format->width - ft_strlen(tmp);
	if (format->width > 0)
		tmp = width(format, tmp);
	format->output = tmp;
	return ;
}
