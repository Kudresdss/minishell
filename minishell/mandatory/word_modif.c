/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_modif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:19:08 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:25:15 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

char	*word_will_double(char *str, int *cur, char *s1)
{
	while (str && str[*cur] && str[*cur] != '"')
	{
		if (str[*cur] == '$')
		{
			s1 = if_env(str, s1, cur);
			if (s1 == NULL)
				return (NULL);
		}
		else
		{
			s1 = if_no_env(str, s1, cur);
			if (s1 == NULL)
				return (NULL);
		}
	}
	return (s1);
}

char	*word_will_single(char *str, int *i, char *s1)
{
	char	*s2;
	char	*s3;
	int		j;

	s2 = NULL;
	s3 = NULL;
	j = *i;
	while (str && str[(*i)] && str[(*i)] != '\'')
		(*i)++;
	s2 = malloc(sizeof(char) * ((*i) - j + 1));
	if (s2 == NULL)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	s2 = ft_strncpy(s2, str + j, (*i) - j);
	s3 = ft_strjoin(s1, s2);
	free_both(s1, s2);
	return (s3);
}

t_quote	update_quote_succes(t_token *stc, int *i, t_quote quote, char **s1)
{
	(*i)++;
	stc->expanded = true;
	if (*s1 == NULL)
	{
		*s1 = malloc(sizeof(char));
		if (*s1 != NULL)
			(*s1)[0] = '\0';
	}
	return (quote);
}

int	word_modif_two(t_token **stc, char *duplica, t_quote quote, t_quote prec)
{
	char	*s1;
	int		cur;
	char	*str;

	if (init_str(&str, duplica, &cur, &s1) == NULL)
		return (50);
	while (str[cur])
	{
		quote = update_quote_status(str[cur], quote);
		if (prec != quote)
			prec = update_quote_succes(*stc, &cur, quote, &s1);
		else
		{
			if (quote == SINGLE)
				s1 = word_will_single(str, &cur, s1);
			else if (quote == DOUBLE)
				s1 = word_will_double(str, &cur, s1);
			else if (quote == NONE)
				s1 = word_will_unquote(stc, str, &cur, s1);
		}
		if (s1 == NULL)
			return (free_str_ret_malloc_error(str));
	}
	return (end_modif_two(str, stc, s1));
}

int	word_modif(t_token **stc, char *str, t_e_token token)
{
	t_quote	quote;
	t_quote	prec;

	quote = NONE;
	prec = NONE;
	if (token == LIMITOR)
		return (limitor(*stc, str));
	return (word_modif_two(stc, str, quote, prec));
}
