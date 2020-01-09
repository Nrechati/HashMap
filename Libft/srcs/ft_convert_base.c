/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:39:07 by nrechati          #+#    #+#             */
/*   Updated: 2019/05/20 11:12:57 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_base_check_and_strlen(char *base)
{
	int		i;
	int		length;

	length = 0;
	while (base[length] != '\0')
	{
		if (base[length] == '+' || base[length] == '-')
			return (0);
		i = length - 1;
		while (i >= 0)
		{
			if (base[i] == base[length])
				return (0);
			i--;
		}
		length++;
	}
	return (length);
}

static int		ft_is_in_base(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sig;
	int		nbase;
	int		value;

	i = 0;
	sig = 1;
	value = 0;
	nbase = ft_base_check_and_strlen(base);
	if (nbase <= 1)
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
		sig *= (str[i++] == '-' ? -1 : 1);
	while (ft_is_in_base(base, str[i]) != -1)
	{
		value = value * nbase + ft_is_in_base(base, str[i]);
		i++;
	}
	if (!str[i] || str[i] == '-' || str[i] == '+')
		return (sig * value);
	else
		return (0);
}

static void		ft_putnbr_base(char **line, char *base_to, int nbr, int i)
{
	int		nbase;
	long	l_nb;

	l_nb = nbr;
	nbase = ft_base_check_and_strlen(base_to);
	if (nbase > 1)
	{
		if (l_nb < 0)
		{
			line[0][0] = ('-');
			ft_putnbr_base(line, base_to, -l_nb, 1);
		}
		else if (l_nb >= nbase)
		{
			ft_putnbr_base(line, base_to, l_nb / nbase, i + 1);
			ft_putnbr_base(line, base_to, l_nb % nbase, i);
		}
		else
			line[0][i] = base_to[l_nb];
	}
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_10;
	int		len;
	int		i;
	char	*tmp_tab;
	char	*line;

	len = 0;
	nbr_10 = ft_atoi_base(nbr, base_from);
	if (!(tmp_tab = (char *)malloc(sizeof(char) * (32 + 1))))
		return (0);
	ft_putnbr_base(&tmp_tab, base_to, nbr_10, 0);
	while (tmp_tab[len] != '\0')
		len++;
	if (!(line = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (len > 0)
	{
		line[i] = tmp_tab[len - 1];
		len--;
		i++;
	}
	free(tmp_tab);
	return (line);
}
