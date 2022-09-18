/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    built_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:36:12 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 17:52:15 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	ft_print_error(char *str1, char *str2)
{
	char	*ret;

	g_exit_status = 1;
	ret = ft_strjoin(str1, str2);
	if (ret == NULL)
		return (50);
	perror(ret);
	free(ret);
	return (0);
}

char	*ft_get_home(void)
{
	t_env	*cpy;
	int		len;

	len = ft_get_lenkey("HOME=");
	cpy = *get_adress_env();
	while (cpy)
	{
		if (len == ft_get_lenkey(cpy->str)
			&& !ft_strncmp(cpy->str, "HOME", len))
		{
			if (ft_equal(cpy->str))
				return (cpy->str + len + 1);
			return (NULL);
		}
		cpy = cpy->next;
	}
	return (NULL);
}

int	ft_pwd(char *s)
{
	char	*oldpwd;
	char	*pwd;
	int		ret;

	ret = 0;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		free(pwd);
		return (50);
	}
	oldpwd = ft_strjoin(s, pwd);
	free(pwd);
	if (oldpwd == NULL)
	{
		free(oldpwd);
		return (50);
	}
	ret = ft_add_env(oldpwd);
	free(oldpwd);
	return (ret);
}

int	ft_built_in_cd(char **str)
{
	if (*(str + 1) == NULL || ft_strcmp(str[1], "~"))
	{
		*(str + 1) = ft_get_home();
		if (*(str + 1) == NULL)
		{
			printf("HOME not set\n");
			return (0);
		}
		if (str[1][0] == '\0')
			return (0);
	}
	if (ft_pwd("OLDPWD=") == 50)
		return (50);
	if (chdir(*(str + 1)) == -1)
		if (ft_print_error("minishell: cd: ", *(str + 1)) == 50)
			return (50);
	if (ft_pwd("PWD=") == 50)
		return (50);
	return (0);
}

int	ft_is_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}
