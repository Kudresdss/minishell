/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:30:59 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 15:06:15 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	unclose_quote(char	*str)
{
	int		i;
	t_quote	quote;

	i = 0;
	quote = NONE;
	while (str[i])
	{
		if (str[i] == '"')
		{
			if (quote == NONE)
				quote = DOUBLE;
			else if (quote == DOUBLE)
				quote = NONE;
		}
		if (str[i] == '\'')
		{
			if (quote == NONE)
				quote = SINGLE;
			else if (quote == SINGLE)
				quote = NONE;
		}
		i++;
	}
	return (quote);
}

t_quote	update_quote_status(char c, t_quote quote)
{
	if (c == '"')
	{
		if (quote == NONE)
			return (DOUBLE);
		else if (quote == DOUBLE)
			return (NONE);
	}
	else if (c == '\'')
	{
		if (quote == NONE)
			return (SINGLE);
		else if (quote == SINGLE)
			return (NONE);
	}
	return (quote);
}

void	to_pipe(int *i, char *str)
{
	t_quote	quote;

	quote = NONE;
	while (str[*i])
	{
		quote = update_quote_status(str[*i], quote);
		if (str[*i] == '|' && quote == NONE)
			return ;
		(*i)++;
	}
	return ;
}
