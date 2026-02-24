/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:37:03 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/24 16:19:46 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	main_scene(t_game *game)
{
	t_player	Player;

	(void)game;
	load_images(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_player, 0, 0);
	free_images(game);
	Player = (t_player){0};

}

void	game_engine(char **map)
{
	t_game	game;

	game.mlx = mlx_init();
	game.map = map;
	window(&game, "Hello so_long", 400, 400);
	mlx_destroy_context(game.mlx);
}
