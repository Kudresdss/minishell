/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:53:18 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 17:54:50 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

void	ft_built_in_show_env(t_env **env)
{
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		if (ft_is_equal(cur->str))
		{
			printf("%s\n", cur->str);
		}
		cur = cur->next;
	}
}

int	ft_built_in_env(char **str)
{
	t_env	**env;

	if (*str == NULL)
		return (0);
	env = get_adress_env();
	ft_built_in_show_env(env);
	return (0);
}

void	ft_built_in_show_env_fd(t_env **env, int fd)
{
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		if (ft_is_equal(cur->str))
		{
			ft_putstr_fd(cur->str, fd);
			ft_putchar_fd('\n', fd);
		}
		cur = cur->next;
	}
}

int	ft_built_in_env_fd(char **str, int fd)
{
	t_env	**env;

	if (*str == NULL)
		return (0);
	env = get_adress_env();
	ft_built_in_show_env_fd(env, fd);
	return (0);
}

int	ft_built_in_unset(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		if (ft_singletone(str[i], DELETE) == 50)
			return (50);
		i++;
	}
	g_exit_status = 0;
	return (0);
}
