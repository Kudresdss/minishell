/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aleatory.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:49:44 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:27:16 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

int	aleatori_char(void)
{
	char	buff[4];
	int		nbr;
	int		fd;

	fd = open("/dev/random", O_RDONLY);
	if (fd < -1)
		return (-1);
	read(fd, buff, 4);
	nbr = *(int *)buff;
	if (nbr < 0)
		nbr++;
	if (nbr < 0)
		nbr = nbr * (-1);
	return ('a' + nbr % 26);
}

char	*creat_aleatori_name(void)
{
	char	*name_file;
	int		i;

	i = 0;
	name_file = malloc(sizeof(char) * 11);
	name_file[10] = '\0';
	while (i < 10)
	{
		name_file[i] = (char)aleatori_char();
		i++;
	}
	return (name_file);
}
