/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:37:19 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/19 18:49:44 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

static void	flood(int x, int y, char **map, int *found_e)
{
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	if (map[x][y] == 'E')
	{
		*found_e = 1;
		return ;
	}
	map[x][y] = 'X';
	flood(x + 1, y, map, found_e);
	flood(x -1, y, map, found_e);
	flood(x, y + 1, map, found_e);
	flood(x, y - 1, map, found_e);
}

int	main_fill(char **map)
{
	int		x_player;
	int		y_player;
	char	**copy;
	int		found_e;

	x_player = 1;
	y_player = 1;
	copy = copy_map(map);
	found_e = 0;
	get_coord(&x_player, &y_player, 'P', copy);
	flood(x_player, y_player, copy, &found_e);
	if (found_e != 1 || counter(copy, 'C'))
	{
		free_map(copy);
		return (error("Flood_fill: all objects are not reachable ($︵$)"));
	}
	free_map(copy);
	return (1);
}
