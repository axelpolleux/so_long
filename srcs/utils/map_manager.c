/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:07:11 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/27 13:30:38 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	check_line(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (error("you forgot up and bottom walls -_-"));
		j++;
	}
	return (1);
}

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
			if (!check_line(map, i))
				return (0);
		}
		else
		{
			while (map[i][j])
			{
				if ((j == 0 || j == width - 1) && map[i][j] != '1')
					return (error("a house without any side walls ? :-|"));
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	check_points(char **map)
{
	if (counter(map, 'P') < 1)
		return (error("I've never seen a game without a player\n(͠≖ ͜ʖ͠≖)"));
	if (counter(map, 'P') > 1)
		return (error("You're not alone in your head, just one player\n0_0"));
	if (counter(map, 'E') < 1)
		return (error("Where will you go, without any exit ?\n(ง ͠° ͟ʖ ͡°)ง"));
	if (counter(map, 'E') > 1)
		return (error("Where will I go, too much exit !\n( •͡˘ _•͡˘)ノð"));
	if (counter(map, 'C') < 1)
		return (error("I'll get bored without any collectibles\n(ಥ﹏ಥ)"));
	return (1);
}
