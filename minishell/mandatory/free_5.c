/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:51:01 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 18:51:22 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

void	ft_clean_env(void)
{
	ft_singletone(NULL, FREE);
}

int	free_str_ret_malloc_error(char *str)
{
	free(str);
	return (50);
}
