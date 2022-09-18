/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ft_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 08:40:19 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:55:41 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	create_and_fill_cmd(char *str, int cur, int start, t_commande_line **first)
{
	t_commande_line	*new;

	new = malloc(sizeof(t_commande_line));
	if (new == NULL)
		return (50);
	init_cmdl(new);
	new->string = malloc(sizeof(char) * (cur - start + 1));
	if (new->string == NULL)
		return (free_cmdl_ret_malloc_error(new));
	new->string = ft_strncpy(new->string, str + start, cur - start);
	cmdl_add_back(first, new);
	return (0);
}

int	get_cmd_line(char *string, t_commande_line **first_stc)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (string[i])
	{
		if (i != 0)
		{
			i++;
			start++;
		}
		to_pipe(&i, string);
		if (create_and_fill_cmd(string, i, start, first_stc) > 0)
			return (50);
		start = i;
		if (i == 0)
		{
			i++;
			start++;
		}
	}
	return (0);
}
