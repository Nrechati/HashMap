/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:55:08 by nrechati          #+#    #+#             */
/*   Updated: 2019/03/12 15:03:31 by nrechati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static char		*word_fill(char *str, int i, int len)
{
	int		w_ind;
	char	*word;

	if (!(word = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	w_ind = 0;
	word[len] = '\0';
	while (len > 0)
	{
		word[len - 1] = str[i - w_ind];
		w_ind++;
		len--;
	}
	return (word);
}

static int		word_counter(char *str, char **tab, int flag, char *charset)
{
	int		i;
	int		w;
	int		len;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && ft_strchr(charset, str[i]))
			i++;
		if (str[i] && !ft_strchr(charset, str[i]))
		{
			len = 0;
			while (str[i] && !ft_strchr(charset, str[i]))
			{
				i++;
				len++;
			}
			if (flag == 1)
				tab[w] = word_fill(str, (i - 1), len);
			w++;
		}
	}
	return (w);
}

char			**ft_strsplit(char const *s, char *charset)
{
	char	**tab;
	int		word_nbr;

	if (!s || !charset)
		return (NULL);
	word_nbr = word_counter((char *)s, 0, 0, charset);
	if (!(tab = (char**)malloc(sizeof(char *) * (word_nbr + 1))))
		return (NULL);
	word_counter((char *)s, tab, 1, charset);
	tab[word_nbr] = 0;
	return (tab);
}
