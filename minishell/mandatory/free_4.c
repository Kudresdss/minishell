/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:22:35 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:26:07 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	free_all_env_str_ret_malloc_error(t_commande_line **cmd, char *str)
{
	free(str);
	free_all(cmd);
	ft_clean_env();
	write(2, "malloc error\n", 13);
	return (50);
}

int	free_all_error(t_commande_line **cmd, char *str, int error)
{
	if (error == 40)
		write(2, "pipe fails\n", 11);
	if (error == 50)
		write(2, "malloc error\n", 13);
	free(str);
	ft_clean_env();
	free_all(cmd);
	return (1);
}

char	*free_split_ret_null(char **split_path)
{
	free_split(split_path);
	return (NULL);
}

void	free_end(t_commande_line **cmd, char *str)
{
	if (str)
		free(str);
	free_all(cmd);
}

int	free_str_all_ret_malloc_error(t_commande_line **cmd, char *str)
{
	free(str);
	free_all(cmd);
	return (50);
}
