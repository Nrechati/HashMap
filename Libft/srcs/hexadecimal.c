/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:26:03 by nrechati          #+#    #+#             */
/*   Updated: 2019/02/05 11:09:20 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	hexadecimal(t_format *format)
{
	char	*tmp;
	char	*holder;
	int		i;

	tmp = unsigned_convert(format);
	holder = tmp;
	tmp = *holder ? ft_convert_base(tmp, TEN, HEXA) : tmp;
	if ((format->precision -= ft_strlen(tmp)) > 0)
		tmp = precision(format, tmp);
	format->width = format->width - ft_strlen(tmp);
	if (format->flag_hashtag && (format->flag_zero || format->flag_minus))
		format->width -= 2;
	if (format->width > 0)
		tmp = width(format, tmp);
	if (format->flag_hashtag && *tmp)
		tmp = prefix(format, tmp);
	if (format->type == 'X' && !(i = 0))
		while ((tmp[i] = ft_toupper(tmp[i])))
			i++;
	if (*holder)
		ft_strdel(&holder);
	format->output = tmp;
	return ;
}
