/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_env_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 08:57:21 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 19:00:09 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

char	*string_env(char *str, char *tmp, int *cur)
{
	char	*tmp2;

	tmp2 = NULL;
	tmp2 = get_env(cur, str);
	if (tmp2 == NULL)
		return (free_str_ret_null(tmp));
	return (tmp2);
}

char	*string_before_env(char *str, char *s1, int *cur, int start)
{
	char	*s2;
	char	*s3;

	s2 = NULL;
	s3 = NULL;
	s2 = malloc(sizeof(char) * ((*cur) - start + 1));
	if (s2 == NULL)
		return (free_str_ret_null(s1));
	s2 = ft_strncpy(s2, str + start, (*cur) - start);
	s3 = ft_strjoin(s1, s2);
	free_both(s1, s2);
	return (s3);
}

char	*end_word_unquote(char *str, char *s1, int *i, int j)
{
	char	*s2;
	char	*s3;

	s2 = NULL;
	s3 = NULL;
	if ((*i) - j == 0)
		return (s1);
	s2 = malloc(sizeof(char) * ((*i) - j + 1));
	if (s2 == NULL)
		return (free_str_ret_null(s1));
	s2 = ft_strncpy(s2, str + j, (*i) - j);
	s3 = ft_strjoin(s1, s2);
	free_both(s1, s2);
	return (s3);
}

char	*if_no_env(char *str, char *s1, int *cur)
{
	char	*new;
	char	*join;
	int		start;

	start = *cur;
	while (str[*cur] && str[*cur] != '"' && str[*cur] != '$')
		(*cur)++;
	new = malloc(sizeof(char) * ((*cur) - start));
	if (new == NULL)
		return (free_str_ret_null(s1));
	new = ft_strncpy(new, str + start, ((*cur) - start));
	join = ft_strjoin(s1, new);
	free_both(s1, new);
	return (join);
}

char	*if_env(char *str, char *s1, int *cur)
{
	char	*env;
	char	*join;

	env = string_env(str, s1, cur);
	if (env == NULL)
		return (free_str_ret_null(s1));
	join = ft_strjoin(s1, env);
	free_both(s1, env);
	return (join);
}
