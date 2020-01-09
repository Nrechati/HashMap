/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:40:19 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/20 11:13:31 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static int		ft_isdone(char *tmp)
{
	if (ft_strchr(tmp, '\n'))
	{
		ft_strcpy(tmp, ft_strchr(tmp, '\n') + 1);
		return (0);
	}
	if (ft_strclen(tmp, '\n') > 0)
	{
		ft_strcpy(tmp, ft_strchr(tmp, '\0'));
		return (0);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		*tab[MAX_FD];
	char			buff[BUFF_SIZE + 1];
	char			*ptr;
	int				res;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(tab[fd]) && (tab[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(tab[fd], '\n'))
			&& (res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		ptr = tab[fd];
		if (!(tab[fd] = ft_strjoin(ptr, buff)))
			return (-1);
		free(ptr);
	}
	*line = ft_strsub(tab[fd], 0, ft_strclen(tab[fd], '\n'));
	if (ft_isdone(tab[fd]))
		return (0);
	return (1);
}
