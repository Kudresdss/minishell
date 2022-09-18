/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:01:35 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 18:50:22 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	no_forking(t_commande_line **cmdl, pid_t *pid)
{
	if ((*cmdl)->argv == NULL)
		return (0);
	else if (ft_exec_bd_fd((*cmdl)->argv[0],
			(*cmdl)->argv, cmdl, pid) != 0)
	{
		return (0);
	}
	return (0);
}

int	exec_builtin(char **str, t_commande_line **cmdl,
		t_commande_line **first, pid_t *pid)
{
	free(str);
	if (ft_exec_builtin((*cmdl)->argv[0], (*cmdl)->argv, first, pid) == 2)
		exit(1);
	exit(0);
	return (0);
}

int	forking(t_commande_line **cmdl, pid_t *pid)
{
	int				len;
	int				i;
	t_commande_line	*cur;

	i = 0;
	cur = *cmdl;
	len = len_cmd(cur);
	while (cur)
	{
		open_fd(&cur);
		cur = cur->next;
	}
	cur = *cmdl;
	if (len == 1 && ft_is_builtin(cur->argv[0]))
	{
		return (no_forking(cmdl, pid));
	}
	while (i < len)
	{
		multi_fork(pid, i, cmdl, &cur);
		cur = cur->next;
		i++;
	}
	return (0);
}
