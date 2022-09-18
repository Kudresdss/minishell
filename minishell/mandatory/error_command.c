/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:10:29 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 18:54:59 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

void	error_str(void)
{
	write(2, "minishell: syntax error near unexpected token '|' \n", 51);
	g_exit_status = 2;
}

int	ret_error_file_without_file(t_commande_line *cur_b)
{
	write(2, "minishell: syntax error", ft_strlen("minishell: syntax error"));
	if (cur_b)
		write(2, " |\n", 3);
	else
		write(2, " newline\n", 9);
	return (12);
}

int	ret_file_without_obj(t_e_token type)
{
	write(2, "minishell: syntax error", ft_strlen("minishell: syntax error"));
	if (type == NON)
		write(2, " newline\n", 9);
	if (type == CREAT_FILE)
		write(2, " >\n", 3);
	else if (type == WRITE_FILE)
		write(2, " >>\n", 4);
	else if (type == OPEN_FILE)
		write(2, " <\n", 3);
	else if (type == HERE_DOC)
		write(2, " <<\n", 4);
	return (12);
}

char	*write_bad_cmd_free_split(char *str, char **split_path)
{
	free_split(split_path);
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, " : command not found\n",
		ft_strlen(" : command not found\n"));
	return (NULL);
}

char	*write_bad_cmd_free(char *str)
{
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, " : command not found\n",
		ft_strlen(" : command not found\n"));
	free(str);
	return (NULL);
}
