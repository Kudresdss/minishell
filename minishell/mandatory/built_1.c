/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:36:28 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 18:53:58 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	ft_built_in_pwd(char **str)
{
	char	*pwd;

	if (*str == NULL)
		return (0);
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (50);
	g_exit_status = 0;
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}

int	ft_built_in_pwd_fd(char **str, int fd)
{
	char	*pwd;

	if (*str == NULL)
		return (0);
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (50);
	g_exit_status = 0;
	ft_putstr_fd(pwd, fd);
	ft_putchar_fd('\n', fd);
	free(pwd);
	return (0);
}

int	ft_check_n(char **str)
{
	int	i;
	int	y;
	int	cpt;

	cpt = 0;
	y = 0;
	i = 0;
	while (str[i] && ft_strlen(str[i]) >= 2)
	{
		if (str[i][y] == '-' && str[i][y + 1] == 'n')
		{
			y++;
			while (str[i][y] == 'n')
				y++;
			if (y == (int)ft_strlen(str[i]))
				cpt++;
		}
		else
			return (cpt);
		i++;
		y = 0;
	}
	return (cpt);
}

int	ft_built_in_echo(char **str)
{
	int	i;
	int	y;

	str++;
	y = 0;
	i = ft_check_n(str);
	if (i > 0)
		y++;
	while (str[i])
	{
		printf("%s", str[i]);
		if (str[i + 1])
			printf(" ");
		i++;
	}
	if (y == 0)
		printf("\n");
	g_exit_status = 0;
	return (0);
}

int	ft_built_in_echo_fd(char **str, int fd)
{
	int	i;
	int	y;

	str++;
	y = 0;
	i = ft_check_n(str);
	if (i > 0)
		y++;
	while (str[i])
	{
		ft_putstr_fd(str[i], fd);
		if (str[i + 1])
			ft_putchar_fd(' ', fd);
		i++;
	}
	if (y == 0)
		ft_putchar_fd('\n', fd);
	g_exit_status = 0;
	return (0);
}
