/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:37:03 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/27 18:18:08 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

static int	count_lines_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	game_engine(char **map)
{
	t_game		game;
	t_player	player;
	int			width;
	int			height;

	game.tile_size = 64;
	player = (t_player){0};
	width = ft_strlen(map[0]) * game.tile_size;
	height = count_lines_map(map) * game.tile_size;
	game.mlx = mlx_init();
	game.map = map;
	game.player = player;
	get_coord(&game.player.pos_y, &game.player.pos_x, 'P', map);
	window(&game, "Hello so_long", width, height);
	mlx_destroy_context(game.mlx);
}
