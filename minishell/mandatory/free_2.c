/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:12:56 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:26:13 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	end_modif_two(char *str, t_token **stc, char *s1)
{
	free(str);
	(*stc)->str = s1;
	return (0);
}

void	free_file_name(char *file_name)
{
	if (file_name != NULL)
	{
		unlink(file_name);
		free(file_name);
	}
}

int	free_in_builin(t_commande_line **first, pid_t *pid, int ret)
{
	free(pid);
	free_all(first);
	ft_clean_env();
	exit (ret);
	return (ret);
}

char	*free_split_token(char **split, t_token *tok)
{
	free_split(split);
	if (tok)
	{
		if (tok->str)
			free(tok->str);
	}
	return (NULL);
}
