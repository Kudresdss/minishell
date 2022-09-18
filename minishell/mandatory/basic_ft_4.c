/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ft_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:26:30 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:28:45 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*start;

	if (b == NULL)
		return (NULL);
	start = b;
	while (len)
	{
		*start = c;
		start++;
		len--;
	}
	return (b);
}

void	fill_new(char *new, int sign, int nbr, int j)
{
	long	cp;
	int		divid;

	cp = nbr * sign;
	divid = 1000000000;
	while (divid > cp)
		divid = divid / 10;
	while (divid >= 10)
	{
		new[j] = cp / divid + '0';
		j++;
		cp = cp % divid;
		divid = divid / 10;
	}
	new[j] = cp + '0';
	new[j + 1] = '\0';
}

void	*ft_memalloc(size_t size)
{
	void	*result;

	result = malloc(size + 1);
	if (result != NULL)
		ft_memset(result, '\0', size);
	return (result);
}

char	*ft_itoa(int nbr)
{
	int		sign;
	char	*new;
	int		j;

	j = 0;
	new = ft_memalloc(len_int(nbr, &sign));
	if (new == NULL)
		return (NULL);
	if (sign == -1)
	{
		new[0] = '-';
		j++;
	}
	fill_new(new, sign, nbr, j);
	return (new);
}

int	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	res = res * sign;
	return ((int)res);
}
