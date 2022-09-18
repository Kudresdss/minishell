/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:20:31 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:30:16 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	edit_type(t_commande_line **block, int limiter)
{
	t_commande_line	*cur_b;
	t_token			*cur_t;

	cur_b = *block;
	while (cur_b)
	{
		cur_t = cur_b->first_token;
		while (cur_t)
		{
			if (cur_t->type == HERE_DOC)
				limiter = 1;
			else if (limiter == 1 && cur_t->str && cur_t->str[0] != '\0')
			{
				if (is_type_file(cur_t->type) == 1)
					return (ret_file_without_obj(cur_t->type));
				cur_t->type = LIMITOR;
				limiter = 0;
			}
			cur_t = cur_t->next;
		}
		if (limiter == 1)
			return (ret_file_without_obj(NON));
		cur_b = cur_b->next;
	}
	return (0);
}

int	check_open_fil(t_commande_line **block)
{
	t_commande_line	*cur_b;
	t_token			*cur_t;
	int				file;
	t_e_token		type;

	cur_b = *block;
	file = 0;
	while (cur_b)
	{
		cur_t = cur_b->first_token;
		while (cur_t)
		{
			if (is_type_file(cur_t->type) == 1 && file == 1)
				return (ret_file_without_obj(cur_t->type));
			else if (is_type_file(cur_t->type) == 1)
				type = cp_type_change_file(cur_t->type, &file);
			else if (file == 1 && cur_t->str && (cur_t->str[0] != '\0'))
				cur_t->type = change_type_file(type, &file);
			cur_t = cur_t->next;
		}
		if (file == 1)
			return (ret_error_file_without_file(cur_b->next));
		cur_b = cur_b->next;
	}
	return (0);
}

int	expend_words(t_commande_line **block)
{
	t_commande_line	*cur_b;
	t_token			*cur_t;
	int				res;

	cur_b = *block;
	if (edit_type(block, 0) != 0 || check_open_fil(block) != 0)
		return (12);
	res = 0;
	while (cur_b)
	{
		cur_t = cur_b->first_token;
		while (cur_t)
		{
			if (cur_t->str && cur_t->str[0] != '\0')
			{
				res = word_modif(&cur_t, cur_t->str, cur_t->type);
				if (res != 0)
					return (50);
			}
			cur_t = cur_t->next;
		}
		cur_b = cur_b->next;
	}
	return (0);
}
