/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:37:19 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/17 19:31:14 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	flood(int x, int y, char **map)
{
	//right
	if (map[x + 1][y] != '1')
		flood(x++, y, map);
	//left
	if (map[x - 1][y] != '1')
		flood(x--, y, map);
	//top
	if (map[x][y - 1] != '1')
		flood(x, y--, map);
	//bottom
	if (map[x][y + 1] != '1')
		flood(x, y++, map);
}

int	main_fill(char **map, int width, int height)
{
	int	x;
	int	y;

	(void)width;
	(void)height;
	x = 1;
	y = 1;
	char	**copy;
	copy = copy_map(map, height);
	flood(x, y, copy);
	return (1);
}
