/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:45:48 by kirill            #+#    #+#             */
/*   Updated: 2022/09/17 14:25:36 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	pars(char *str, t_commande_line **cmd_line)
{
	int	res;

	res = unclose_quote(str);
	if (res > 0)
	{
		write(2, "minishell: miss quote\n", 22);
		free_all(cmd_line);
	}
	else
	{
		if (get_cmd_line(str, cmd_line) > 0)
			return (free_str_all_ret_malloc_error(cmd_line, str));
		if (split_all_cmdl_string_to_token(cmd_line) > 0)
			return (free_str_all_ret_malloc_error(cmd_line, str));
		res = expend_words(cmd_line);
		if (res != 0)
		{
			free_all(cmd_line);
			if (res == 50)
				return (free_str_ret_malloc_error(str));
		}
		if (organise_arg(cmd_line) != 0)
			return (free_str_all_ret_malloc_error(cmd_line, str));
	}
	return (res);
}
