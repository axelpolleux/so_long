/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:02:21 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/25 19:48:17 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_other(t_game *game)
{
	int		i;
	int		j;
	int		tile_size;
	char	**map;

	i = 0;
	tile_size = game->tile_size;
	map = game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
					j * tile_size, i * tile_size);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collectible,
					j * tile_size, i * tile_size);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
					j * tile_size, i * tile_size);
			j++;
		}
		i++;
	}
}

static void	display_map(t_game *game)
{
	int		i;
	int		j;
	int		tile_size;
	char	**map;

	i = 0;
	tile_size = game->tile_size;
	map = game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * tile_size, i * tile_size);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, j * tile_size, i * tile_size);
			j++;
		}
		i++;
	}
}

void	update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	display_map(game);
	display_other(game);
}
