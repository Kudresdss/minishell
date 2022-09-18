/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:47:04 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 15:08:05 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

void	token_add_back(t_token **first, t_token *add_back)
{
	t_token	*cur;

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

int	create_add_back_token(int cur, int start, char *str,
		t_commande_line **stc)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		return (50);
	init_token(new);
	new->str = malloc(sizeof(char *) * (cur - start + 1));
	if (new->str == NULL)
		return (free_token_ret_malloc_error(new));
	new->str = ft_strncpy(new->str, str + start, cur - start);
	init_type(new);
	token_add_back(&((*stc)->first_token), new);
	return (0);
}

void	iter_to_end_or_redirection(char	*str, int *cur)
{
	char	c;

	c = str[*cur];
	while (str[*cur] && str[*cur] == c)
		(*cur)++;
}
