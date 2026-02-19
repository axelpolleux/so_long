/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:09:21 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/19 17:43:51 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"

int	not_this_char(char **map, char *chars)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
			if (ft_strchr(chars, map[i][j]) == 0)
				return (error("Character not accepted"));
		}
		i++;
	}
	return (1);
}

void	get_coord(int *x, int *y, char find, char **map)
{
	int	i;

	i = 0;
	while (ft_strichr(*map, find) == -1)
	{
		map++;
		i++;
	}
	*y = ft_strichr(*map, find);
	*x = i;
}

char	*get_line(int fd)
{
	int		limit;
	char	*tmp;
	char	*res;

	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	limit = ft_strichr(tmp, '\n');
	if (limit == -1)
		return (tmp);
	res = ft_substr(tmp, 0, limit);
	if (!res)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (res);
}

void	drain_gnl(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
}
