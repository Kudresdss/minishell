/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multy_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:59:44 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:25:46 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

char	**env_to_tabtab(t_env **envp)
{
	char	**new;
	t_env	*cur;
	int		i;

	i = 0;
	cur = *envp;
	while (cur)
	{
		cur = cur->next;
		i++;
	}
	new = malloc(sizeof(char *) * (i + 1));
	new[i] = NULL;
	cur = *envp;
	i = 0;
	while (cur)
	{
		new[i] = cur->str;
		i++;
		cur = cur->next;
	}
	return (new);
}

int	ft_exec_cmd(t_commande_line **cmdl, t_commande_line **first,
	char **str, pid_t *pid)
{
	struct stat	buff;

	execve((*cmdl)->argv[0], (*cmdl)->argv, str);
	if (stat((*cmdl)->argv[0], &buff) == 0)
	{
		write(2, "minishell: ", ft_strlen("minishell: "));
		write(2, (*cmdl)->argv[0], ft_strlen((*cmdl)->argv[0]));
		write(2, ": Permission denied\n", ft_strlen(": Permission denied\n"));
		exit(126);
	}
	free_all(first);
	free(str);
	free(pid);
	ft_clean_env();
	g_exit_status = 127;
	exit(g_exit_status);
	return (0);
}

int	ft_execve_fct(t_commande_line **cmdl, t_commande_line **first, pid_t *pid)
{
	char		**str;

	dup2((*cmdl)->fd_in, STDIN_FILENO);
	dup2((*cmdl)->fd_out, STDOUT_FILENO);
	close_fd_all(first);
	str = env_to_tabtab(get_adress_env());
	if (str == NULL)
		free_fd_all_exit_malloc_error(first);
	if (ft_is_builtin((*cmdl)->argv[0]) == 0)
	{
		if ((*cmdl)->argv[0] == NULL)
			free_str_fd_all_env_pid_exit(first, pid, str);
		(*cmdl)->argv[0] = get_bin_argv_zero((*cmdl)->argv[0],
				ft_get_env("PATH"), 0);
	}
	if ((*cmdl)->argv[0] == NULL)
		free_str_fd_exit_malloc_error(str, first);
	free_file_name((*cmdl)->name_file);
	if ((*cmdl)->fd_in < 0 || (*cmdl)->fd_out < 0)
		free_str_fd_all_env_pid_exit(first, pid, str);
	if (ft_is_builtin((*cmdl)->argv[0]))
		exec_builtin(str, cmdl, first, pid);
	else
		ft_exec_cmd(cmdl, first, str, pid);
	return (0);
}

int	multi_fork(pid_t *pid, int i, t_commande_line **cmdl, t_commande_line **cur)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid[i] = fork();
	if (pid[i] == -1)
		exit(1);
	if (pid[i] == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		ft_execve_fct(cur, cmdl, pid);
	}
	if ((*cur)->fd_in != 0)
		close((*cur)->fd_in);
	if ((*cur)->fd_out != 1)
		close((*cur)->fd_out);
	return (0);
}
