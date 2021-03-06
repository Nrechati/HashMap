/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widthprec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:08:00 by cempassi          #+#    #+#             */
/*   Updated: 2019/02/05 11:09:20 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*precision(t_format *format, char *tmp)
{
	char	*holder;
	char	*prc;

	holder = tmp;
	prc = ft_strnew(format->precision);
	ft_memset(prc, '0', format->precision);
	tmp = ft_strjoin(prc, holder);
	ft_strdel(&holder);
	ft_strdel(&prc);
	return (tmp);
}

char		*width(t_format *format, char *tmp)
{
	char	*width;
	char	*holder;

	holder = tmp;
	width = ft_strnew(format->width);
	if (format->flag_zero == 1)
		ft_memset(width, '0', format->width);
	else
		ft_memset(width, ' ', format->width);
	if (format->flag_minus)
		tmp = ft_strjoin(tmp, width);
	else
		tmp = ft_strjoin(width, tmp);
	ft_strdel(&holder);
	ft_strdel(&width);
	return (tmp);
}

char		*prefix(t_format *format, char *tmp)
{
	char	*holder;
	int		i;

	i = 0;
	if (*tmp == ' ')
	{
		while (tmp[i] == ' ' && tmp[i + 1] == ' ')
			i++;
		if (ft_strchr("xXb", format->type) && i)
		{
			tmp[i - 1] = '0';
			tmp[i] = format->type;
		}
	}
	else if ((holder = tmp))
	{
		tmp = format->type == 'x' ? ft_strjoin("0x", tmp) : tmp;
		tmp = format->type == 'X' ? ft_strjoin("0x", tmp) : tmp;
		tmp = format->type == 'b' ? ft_strjoin("0b", tmp) : tmp;
		ft_strdel(&holder);
	}
	return (tmp);
}

char		*sign(t_format *format, char *tmp, char flag)
{
	int i;

	i = 0;
	while (tmp[i] == ' ' && tmp[i + 1] == ' ')
		i++;
	if (tmp[i] == ' ')
		tmp[i] = flag;
	else if (tmp[i] == '0' && format->precision < 0)
		tmp[i] = flag;
	else
		tmp = ft_strinsert(&tmp, flag, 0);
	return (tmp);
}

char		*unsigned_convert(t_format *format)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strequ(format->size, "l") || ft_strchr("OU", format->type))
		tmp = ft_ullitoa(format->arg.ul_integer);
	else if (ft_strequ(format->size, "ll") || ft_strequ(format->size, "L"))
		tmp = ft_ullitoa(format->arg.ull_integer);
	else if (ft_strequ(format->size, "j"))
		tmp = ft_ullitoa(format->arg.u_intmax);
	else
		tmp = ft_ullitoa(format->arg.u_integer);
	if (*tmp == '0' && format->precision == 0)
		*tmp = '\0';
	return (tmp);
}
