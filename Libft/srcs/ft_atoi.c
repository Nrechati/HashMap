/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:59:49 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/07 16:23:44 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int	i;
	int	value;
	int	neg;

	i = 0;
	value = 0;
	neg = 0;
	if (str == NULL)
		return (0);
	while (ft_isspace((char)str[i]))
		i++;
	if (str[i] == '-')
		neg++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - 48);
		i++;
	}
	if (neg == 1)
		return (-value);
	else
		return (value);
}
