/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:24:39 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 19:08:28 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

void	signal_cmd_2(int sig)
{
	g_exit_status += sig;
	if (sig == 2)
	{
		g_exit_status = 130;
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_cmd(int sig)
{
	g_exit_status += sig;
	if (sig == 2)
	{
		g_exit_status = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		write(2, "Quit (core dumped)\n", ft_strlen("Quit (core dumped)\n"));
		exit (1);
	}
}

int	wait_pid(t_commande_line **cmdl, pid_t *pid)
{
	t_commande_line	*cur;
	int				len;
	int				i;

	i = 0;
	cur = *cmdl;
	len = len_cmd(cur);
	if (len == 1 && ft_is_builtin((*cmdl)->argv[0]))
	{
		return (0);
	}
	while (i < len)
	{
		waitpid(pid[i], &g_exit_status, 0);
		if (WIFEXITED(g_exit_status))
			g_exit_status = WEXITSTATUS(g_exit_status);
		else if (WIFSIGNALED(g_exit_status))
			g_exit_status = 128 + WTERMSIG(g_exit_status);
		i++;
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	char			*str;
	t_commande_line	*cmd_line;

	cmd_line = NULL;
	g_exit_status = 0;
	ft_init_t_env(envp);
	signal(SIGINT, signal_cmd);
	signal(SIGQUIT, SIG_IGN);
	if (!ac && !av)
		return (0);
	while (1)
	{
		str = readline("minishell$> ");
		add_history(str);
		signal(SIGINT, signal_cmd);
		signal(SIGQUIT, SIG_IGN);
		if (str == NULL)
			return (print_exit_free_env_all(&cmd_line));
		if (check_str(str))
			error_str();
		else
			to_exec(&cmd_line, str);
		free_end(&cmd_line, str);
	}
}
