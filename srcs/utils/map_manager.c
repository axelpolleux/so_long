/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:07:11 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/13 17:51:32 by apolleux         ###   ########.fr       */
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
					return (0);
		}
		else
		{
			while (map[i][j])
			{
				if ((j == 0 || j == width - 1) && map[i][j] != '\n'
					&& map[i][j] != '1')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	counter(char **map)
{
	(void)map;
	return (0);
}