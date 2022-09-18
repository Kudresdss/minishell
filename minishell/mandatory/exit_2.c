/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:06:53 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:26:31 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

void	free_fd_all_exit_malloc_error(t_commande_line **first)
{
	close_fd_all(first);
	exit (50);
}

void	free_str_fd_exit_malloc_error(char **str, t_commande_line **first)
{
	free(str);
	close_fd_all(first);
	exit (50);
}

void	free_str_exit_fd_error(char **str)
{
	free(str);
	exit(1);
}

void	free_str_fd_all_env_pid_exit(t_commande_line **cmd,
	pid_t *pid, char **str)
{
	free_all(cmd);
	ft_clean_env();
	free(pid);
	free(str);
	exit(1);
}

int	print_exit_free_env_all(t_commande_line **cmd)
{
	printf("exit\n");
	ft_clean_env();
	return (free_all(cmd));
}
