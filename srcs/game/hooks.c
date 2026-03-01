/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:02:21 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/01 16:02:01 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_player(t_game *game)
{
	int	tile_size;
	int	j;
	int	i;

	tile_size = game->tile_size;
	i = game->player.pos_y;
	j = game->player.pos_x;
	mlx_put_image_to_window(game->mlx, game->win, game->img_player, j
		* tile_size, i * tile_size);
}

static void	display_objects(t_game *game)
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
			if (map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collectible, j * tile_size, i * tile_size);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j
					* tile_size, i * tile_size);
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
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j
					* tile_size, i * tile_size);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, j
					* tile_size, i * tile_size);
			j++;
		}
		i++;
	}
}

void	update(void *param)
{
	mlx_color	color;
	t_game		*game;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	color.a = 255;
	game = (t_game *)param;
	mlx_clear_window(game->mlx, game->win, color);
	display_map(game);
	display_objects(game);
	display_player(game);
}
