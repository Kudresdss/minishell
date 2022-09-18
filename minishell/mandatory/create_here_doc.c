/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:55:04 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 18:49:44 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

char	*if_no_envy(char *str, char *s1, int *cur)
{
	char	*new;
	char	*join;
	int		start;

	start = *cur;
	while (str[*cur] && str[*cur] != '$')
		(*cur)++;
	new = malloc(sizeof(char) * ((*cur) - start));
	if (new == NULL)
		return (free_str_ret_null(s1));
	new = ft_strncpy(new, str + start, ((*cur) - start));
	join = ft_strjoin(s1, new);
	free_both(s1, new);
	return (join);
}

char	*if_envy(char *str, char *s1, int *cur)
{
	char	*env;
	char	*join;

	env = string_env(str, s1, cur);
	if (env == NULL)
		return (free_str_ret_null(s1));
	join = ft_strjoin(s1, env);
	free_both(s1, env);
	return (join);
}

char	*expanded_str(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			new = if_envy(str, new, &i);
			if (new == NULL)
				return (NULL);
		}
		else
		{
			new = if_no_envy(str, new, &i);
			if (new == NULL)
				return (NULL);
		}
	}
	free(str);
	return (new);
}

int	write_in_fd(int fd, char *limitor, bool expanded)
{
	char	*str;

	while (1)
	{
		str = readline(">");
		if (str == NULL)
			return (45);
		if (ft_strcmp(limitor, str) == 1)
			break ;
		if (str[0] != '\0')
		{
			if (expanded == 0)
			{
				str = expanded_str(str);
				if (str == NULL)
					return (50);
			}
		}
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
	}
	free(str);
	return (0);
}

int	create_heredoc_fd(t_commande_line **cmdl, t_token **cur)
{
	int		fd;
	char	*name_file;

	name_file = NULL;
	fd = -1;
	while (fd == -1)
	{
		if (name_file)
			free(name_file);
		name_file = creat_aleatori_name();
		fd = open(name_file, O_CREAT | O_EXCL | O_RDWR, 0644);
	}
	write_in_fd(fd, (*cur)->str, (*cur)->expanded);
	fd = open(name_file, O_RDONLY);
	(*cmdl)->fd_in = fd;
	if ((*cmdl)->name_file != NULL)
	{
		unlink((*cmdl)->name_file);
		free((*cmdl)->name_file);
	}
	(*cmdl)->name_file = name_file;
	return (fd);
}
