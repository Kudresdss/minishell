/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ft_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:48:44 by ymirna            #+#    #+#             */
/*   Updated: 2022/09/17 14:28:14 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/min.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = ft_memalloc(size);
	return (str);
}

int	ft_strncmp(char *str, char *to, int n)
{
	int	i;

	i = 0;
	if (str == NULL || to == NULL)
		return (-1);
	if ((int)ft_strlen(str) < n || (int)ft_strlen(to) < n)
		return (-1);
	while (i < n)
	{
		if (!str[i] || !to[i] || str[i] != to[i])
			return (str[i] - to[i]);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *str, char *in)
{
	int	len_str;
	int	len_in;
	int	i;

	i = 0;
	len_str = 0;
	len_in = 0;
	len_str = ft_strlen(str);
	len_in = ft_strlen(in);
	if (len_str != len_in)
		return (0);
	while (i < len_in)
	{
		if (str[i] != in[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_alpha_num(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (0);
	return (1);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
