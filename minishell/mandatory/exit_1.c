/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 05:54:49 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:26:33 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	ft_sup_int(char *str)
{
	long	res;
	int		sig;
	int		i;

	res = 0;
	sig = 1;
	i = 0;
	if (str[i] == '-')
	{
		i++;
		sig = -1;
	}
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
		if (res > 2147483648)
			return (2);
	}
	res = res * sig;
	if (res > 2147483647)
		return (2);
	return (0);
}

int	ft_non_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "minishell: exit: ", 17);
			write(2, str, ft_strlen(str));
			write(2, ": numeric argument required\n", 28);
			return (2);
		}
		i++;
	}
	return (ft_sup_int(str));
}

int	exit_bltin(char **args, t_commande_line **first, pid_t *pid)
{
	int	ret;

	ret = 0;
	printf("exit\n");
	if (args[1] != NULL)
	{
		if (ft_non_int(args[1]))
		{
			ft_clean_env();
			free_all(first);
			free(pid);
			exit (2);
		}
		ret = ft_atoi(args[1]);
		if (args[2] != NULL)
		{
			write(2, "minishell: exit: too many arguments\n", 36);
			g_exit_status = 1;
			return (2);
		}
		free_in_builin(first, pid, ret);
	}
	return (free_in_builin(first, pid, 0));
}
