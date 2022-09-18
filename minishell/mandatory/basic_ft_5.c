/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ft_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:56:53 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 15:18:40 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	len_cmd(t_commande_line *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		i++;
		cmd = cmd->next;
	}
	return (i);
}

int	len_int(int nbr, int *sign)
{
	int	i;

	*sign = 1;
	i = 1;
	if (nbr < 0)
	{
		*sign = -1;
		i++;
	}
	while (nbr >= 10)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

int	ft_count_words(const char *s, char c)
{
	int		number;
	int		i;

	i = 0;
	number = 0;
	while (*s)
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			number++;
		}
		s++;
	}
	return (number);
}

void	spliting(int words, char const *s, char c, char **tab)
{
	int	j;
	int	i;
	int	start;

	j = -1;
	i = 0;
	while (++j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_strsub(s, start, i - start);
		i++;
	}
	tab[j] = NULL;
}

char	**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**tab;

	if (!s || !c)
		return (NULL);
	words = ft_count_words(s, c);
	tab = malloc((sizeof(char *) * (words + 1)));
	if (tab == NULL)
		return (NULL);
	spliting(words, s, c, tab);
	return (tab);
}
