/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:40:38 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:25:54 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

void	init_token(t_token *new)
{
	new->str = NULL;
	new->type = NON;
	new->expanded = false;
	new->next = NULL;
}

void	init_type(t_token *new)
{
	int	len;

	len = 0;
	if (new->str)
		len = ft_strlen(new->str);
	if (len == 1)
	{
		if (new->str[0] == '<')
			new->type = OPEN_FILE;
		else if (new->str[0] == '>')
			new->type = CREAT_FILE;
	}
	if (len == 2)
	{
		if (new->str[0] == '<' && new->str[1] == '<')
			new->type = HERE_DOC;
		if (new->str[0] == '>' && new->str[1] == '>')
			new->type = WRITE_FILE;
	}
	if (ft_is_builtin(new->str))
		new->type = BUILTIN;
	if (new->type == NON && len != 0)
		new->type = ARG;
}
