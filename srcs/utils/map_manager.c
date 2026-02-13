/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:07:11 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/13 18:58:57 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (i == 0 || i == height - 1)
		{
			while (map[i][++j])
				if (map[i][j] != '1' && map[i][j] != '\n')
					return (error("a house without any side walls ? :-|"));
		}
		else
		{
			while (map[i][j])
			{
				if ((j == 0 || j == width - 1) && map[i][j] != '\n'
					&& map[i][j] != '1')
					return (error("Map must be surrounded in both sides"));
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	counter(char **map, int character)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == character)
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

int	check_points(char **map)
{
	if (counter(map, 'P') != 1)
		return (error("I've never seen a game without a player"));
	if (counter(map, 'E') != 1)
		return (error("Where will you go, without any exit ?"));
	if (counter(map, 'C') < 1)
		return (error("I'll get bored without any collectibles"));
	return (1);
}
