/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ft_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:13:36 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:26:25 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	is_type_file(t_e_token type)
{
	if (type == CREAT_FILE || type == WRITE_FILE
		|| type == OPEN_FILE || type == HERE_DOC)
		return (1);
	return (0);
}

t_e_token	cp_type_change_file(t_e_token type, int *file)
{
	*file = 1;
	return (type);
}

char	*get_acces(char *str, char *path)
{
	char	*back_slash;
	char	*new;

	back_slash = ft_strjoin(path, "/");
	if (back_slash == NULL)
		return (NULL);
	new = ft_strjoin(back_slash, str);
	free(back_slash);
	if (new == NULL)
		return (NULL);
	return (new);
}

int	try_acces(char *str, char *path)
{
	char	*try;

	try = get_acces(str, path);
	if (try == NULL)
		return (50);
	if (access(try, X_OK) == 0)
	{
		free(try);
		return (1);
	}
	free(try);
	return (0);
}

char	*get_bin_argv_zero(char *str, char *path, int i)
{
	int		ret;
	char	**split_path;
	char	*try;

	if (str && (str[0] == '.' || str[0] == '/'))
		return (str);
	split_path = ft_strsplit(path, ':');
	if (split_path == NULL)
		return (write_bad_cmd_free(str));
	while (split_path[i] && str[0] != '\0')
	{
		ret = try_acces(str, split_path[i]);
		if (ret == 1)
		{
			try = get_acces(str, split_path[i]);
			free_split(split_path);
			return (try);
		}
		if (ret == 50)
			return (free_split_ret_null(split_path));
		i++;
	}
	write_bad_cmd_free_split(str, split_path);
	g_exit_status = 127;
	return (str);
}
