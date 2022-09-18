/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:55:51 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 18:57:19 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	ft_is_builtin(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp("exit", str))
		return (2);
	if (ft_strcmp("cd", str))
		return (1);
	else if (ft_strcmp("echo", str))
		return (1);
	else if (ft_strcmp("env", str))
		return (1);
	else if (ft_strcmp("pwd", str))
		return (1);
	else if (ft_strcmp("export", str))
		return (1);
	else if (ft_strcmp("unset", str))
		return (1);
	return (0);
}

t_e_token	change_type_file(t_e_token type, int *file)
{
	*file = 0;
	if (type == OPEN_FILE)
		return (FILE_IN);
	else if (type == CREAT_FILE)
		return (FILE_OUT);
	else if (type == WRITE_FILE)
		return (FILE_OUT_OVER);
	else if (type == HERE_DOC)
		return (LIMITOR);
	return (NON);
}

int	ft_exec_bd_fd(char *str, char **args, t_commande_line **first, pid_t *pid)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp("exit", str))
	{
		exit_bltin(args, first, pid);
		return (1);
	}
	if (ft_strcmp("cd", str))
		ft_built_in_cd(args);
	else if (ft_strcmp("echo", str))
		ft_built_in_echo_fd(args, (*first)->fd_out);
	else if (ft_strcmp("env", str))
		ft_built_in_env_fd(args, (*first)->fd_out);
	else if (ft_strcmp("pwd", str))
		ft_built_in_pwd_fd(args, (*first)->fd_out);
	else if (ft_strcmp("export", str))
		ft_built_in_export_fd(args, (*first)->fd_out);
	else if (ft_strcmp("unset", str))
		ft_built_in_unset(args);
	return (0);
}

int	ft_exec_builtin(char *str, char **args, t_commande_line **first, pid_t *pid)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp("exit", str))
	{
		exit_bltin(args, first, pid);
		return (free_in_builin(first, pid, 1));
	}
	if (ft_strcmp("cd", str))
		ft_built_in_cd(args);
	else if (ft_strcmp("echo", str))
		ft_built_in_echo(args);
	else if (ft_strcmp("env", str))
		ft_built_in_env(args);
	else if (ft_strcmp("pwd", str))
		ft_built_in_pwd(args);
	else if (ft_strcmp("export", str))
		ft_built_in_export(args);
	else if (ft_strcmp("unset", str))
		ft_built_in_unset(args);
	free(pid);
	ft_clean_env();
	free_all(first);
	return (0);
}
