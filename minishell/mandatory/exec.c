/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:04:59 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:26:36 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	ft_exec(t_commande_line **cmdl)
{
	t_commande_line	*cur;
	pid_t			*pid;
	int				ret;

	cur = *cmdl;
	ret = open_pipe(cmdl);
	if (ret != 0)
		return (ret);
	pid = malloc(sizeof(pid_t) * len_cmd(cur));
	if (pid == NULL)
		return (50);
	forking(cmdl, pid);
	signal(SIGINT, signal_cmd_2);
	signal(SIGQUIT, SIG_IGN);
	wait_pid(cmdl, pid);
	signal(SIGINT, signal_cmd);
	signal(SIGQUIT, SIG_IGN);
	free(pid);
	return (0);
}

void	to_exec(t_commande_line **cmd_line, char *str)
{
	int	res;

	res = pars(str, cmd_line);
	if (res == 50)
	{
		free_all_env_str_ret_malloc_error(cmd_line, str);
		exit (1);
	}
	if (res == 0)
	{
		if (str != NULL && *cmd_line != NULL)
		{
			res = ft_exec(cmd_line);
			if (res != 0)
			{
				free_all_error(cmd_line, str, res);
				exit (1);
			}
		}
	}
}
