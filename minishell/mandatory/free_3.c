/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:21:32 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:26:10 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	free_cmdl_ret_malloc_error(t_commande_line *stc)
{
	if (stc)
		free(stc);
	return (50);
}

int	free_token_ret_malloc_error(t_token *tok)
{
	if (tok)
		free(tok);
	return (50);
}

char	*free_str_ret_null(char *s1)
{
	if (s1)
		free(s1);
	return (NULL);
}

void	free_both(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return ;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
	}
	if (split)
		free(split);
}
