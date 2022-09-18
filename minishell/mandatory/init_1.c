/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:33:07 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:56:50 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

char	*init_str(char **str, char *duplica, int *cur, char **s1)
{
	*s1 = NULL;
	*cur = 0;
	*str = ft_strdup(duplica);
	free(duplica);
	if (*str == NULL)
		return (NULL);
	return (*str);
}

void	init_cmdl(t_commande_line *new)
{
	new->string = NULL;
	new->first_token = NULL;
	new->argv = NULL;
	new->name_file = NULL;
	new->next = NULL;
}

void	cmdl_add_back(t_commande_line **first, t_commande_line *add_back)
{
	t_commande_line	*cur;

	cur = *first;
	if (cur == NULL)
		*first = add_back;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = add_back;
	}
}
