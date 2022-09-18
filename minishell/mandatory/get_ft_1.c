/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ft_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 07:49:36 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:26:04 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

char	*ft_get_str(char *str)
{
	t_env	**env_list;

	env_list = get_adress_env();
	return (ft_get_str_of_env(env_list, str));
}

char	*ft_get_str_of_env(t_env **env, char *str)
{
	t_env	*cpy;
	int		len;

	len = ft_get_lenkey(str);
	cpy = *env;
	while (cpy)
	{
		if (len == ft_get_lenkey(cpy->str) && !ft_strncmp(cpy->str, str, len))
			return (cpy->str);
		cpy = cpy->next;
	}
	return (NULL);
}

char	*ft_get_env(char *str)
{
	t_env	**env_list;

	env_list = get_adress_env();
	return (ft_get_value_of_env(env_list, str));
}

char	*ft_get_value_of_env(t_env **env, char *str)
{
	t_env	*cpy;
	int		len;

	len = ft_get_lenkey(str);
	cpy = *env;
	while (cpy)
	{
		if (len == ft_get_lenkey(cpy->str) && !ft_strncmp(cpy->str, str, len))
			return (cpy->str + len + 1);
		cpy = cpy->next;
	}
	return (NULL);
}
