/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:45:38 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 15:06:54 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	iter_to_end_arg(int *cur, char *str)
{
	t_quote	quote;

	quote = NONE;
	while (str[(*cur)])
	{
		quote = update_quote_status(str[*cur], quote);
		if (is_separator(str[*cur]) == 1 && quote == NONE)
			break ;
		(*cur)++;
	}
	return (0);
}

int	split_string_cur_cmdl(t_commande_line **stc)
{
	int		cur;
	int		start;
	int		len;

	cur = 0;
	len = 0;
	if ((*stc)->string != NULL)
		len = ft_strlen((*stc)->string);
	while (cur < len)
	{
		while (cur < len && (*stc)->string[cur] == ' ')
			cur++;
		start = cur;
		if ((*stc)->string[cur] && is_redirection((*stc)->string[cur]))
			iter_to_end_or_redirection((*stc)->string, &cur);
		else
		{
			iter_to_end_arg(&cur, (*stc)->string);
		}
		if (create_add_back_token(cur, start, (*stc)->string, stc) > 0)
			return (50);
	}
	return (0);
}

int	split_all_cmdl_string_to_token(t_commande_line **first)
{
	t_commande_line	*cur;

	cur = *first;
	while (cur)
	{
		if (split_string_cur_cmdl(&cur) > 0)
			return (50);
		cur = cur->next;
	}
	return (0);
}
