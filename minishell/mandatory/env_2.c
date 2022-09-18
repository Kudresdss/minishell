/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 06:02:05 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:42:03 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	ft_delete_env(char *str)
{
	return (ft_singletone(str, DELETE));
}

void	ft_delete_env_call(t_env **env, char *key)
{
	t_env	*cpy;
	t_env	*prev;
	int		len;

	len = ft_get_lenkey(key);
	prev = NULL;
	cpy = *env;
	while (cpy)
	{
		if (len == ft_get_lenkey(cpy->str) && !ft_strncmp(cpy->str, key, len))
		{
			if (prev == NULL)
				*env = cpy->next;
			else
				prev->next = cpy->next;
			ft_free_env_elem(cpy);
			return ;
		}
		prev = cpy;
		cpy = cpy->next;
	}
}

char	*ft_final_add(char *env)
{
	int		len;
	char	*s;
	int		i;
	int		y;

	i = 0;
	y = 0;
	len = ft_get_lenkey(env) - 1;
	if (env[ft_get_lenkey(env) - 1] != '+')
		return (ft_strdup(env));
	s = malloc(sizeof(char) * ft_strlen(env));
	if (s == NULL)
		return (NULL);
	while (env[y])
	{
		s[i] = env[y];
		i++;
		y++;
		if (y == len)
			y++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_push_front(char *env, t_env **begin_lst, int declare)
{
	t_env	*env_new;

	env_new = malloc(sizeof(t_env));
	if (env_new == NULL)
		return (50);
	env_new->str = ft_final_add(env);
	env_new->declare = declare;
	if (env_new->str == NULL)
		return (50);
	env_new->next = *begin_lst;
	*begin_lst = env_new;
	return (0);
}
