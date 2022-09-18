/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 04:03:02 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 18:51:17 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

void	ft_clean_envlist(t_env **env)
{
	t_env	*cpy;
	t_env	*tmp;

	cpy = *env;
	tmp = cpy;
	while (cpy)
	{
		tmp = cpy;
		cpy = cpy->next;
		free(tmp->str);
		free(tmp);
	}
}

void	ft_free_env_elem(t_env *env)
{
	free(env->str);
	free(env);
}

int	ft_singletone(char *str, int mode)
{
	t_env	**env_list;

	env_list = get_adress_env();
	if (mode == DELETE)
	{
		ft_delete_env_call(env_list, str);
		return (0);
	}
	if (mode == FREE)
		ft_clean_envlist(env_list);
	if (mode == ADD)
	{
		if (ft_add_value_to_env(env_list, str, 0) == 50)
		{
			ft_clean_envlist(env_list);
			return (50);
		}
	}
	return (0);
}

void	free_token(t_commande_line **cmd_line)
{
	t_token	*tok;

	while ((*cmd_line)->first_token)
	{
		tok = (*cmd_line)->first_token->next;
		if ((*cmd_line)->first_token->str)
			free((*cmd_line)->first_token->str);
		free((*cmd_line)->first_token);
		(*cmd_line)->first_token = tok;
	}
}

int	free_all(t_commande_line **cmd_line)
{
	t_commande_line	*tmp;

	if (cmd_line)
	{
		while (*cmd_line)
		{
			tmp = (*cmd_line)->next;
			if ((*cmd_line)->string)
				free((*cmd_line)->string);
			if ((*cmd_line)->argv)
				free((*cmd_line)->argv);
			if ((*cmd_line)->first_token)
				free_token(cmd_line);
			if ((*cmd_line)->name_file)
				free((*cmd_line)->name_file);
			free((*cmd_line));
			*cmd_line = tmp;
		}
	}
	return (1);
}
