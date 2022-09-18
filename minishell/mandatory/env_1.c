/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 05:32:20 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:29:06 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	ft_add_env(char *str)
{
	return (ft_singletone(str, ADD));
}

int	ft_get_lenkey(char *env)
{
	int	i;

	i = 0;
	while (env[i] != '\0' && env[i] != '=')
		i++;
	return (i);
}

int	ft_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	ft_special_lenkey(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=' && str[i] != '+')
		i++;
	return (i);
}

int	ft_add_value_to_env(t_env **env_list, char *env, int declare)
{
	int		len;
	t_env	*cpy;

	cpy = *env_list;
	len = ft_special_lenkey(env);
	while (cpy)
	{
		declare = cpy->declare;
		if (len == ft_get_lenkey(cpy->str) && !ft_strncmp(env, cpy->str, len))
		{
			if (ft_equal(cpy->str) && !ft_equal(env))
				return (0);
			free(cpy->str);
			cpy->str = ft_final_add(env);
			if (cpy->str == NULL)
			{
				ft_clean_envlist(get_adress_env());
				return (50);
			}
			return (0);
		}
		cpy = cpy->next;
	}
	return (ft_push_front(env, env_list, declare));
}
