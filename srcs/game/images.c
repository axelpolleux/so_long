/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:02:13 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/25 19:47:31 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	game->img_player = mlx_new_image_from_file(game->mlx,
			"textures/player.png", NULL, NULL);
	game->img_wall = mlx_new_image_from_file(game->mlx,
			"textures/wall.png", NULL, NULL);
	game->img_floor = mlx_new_image_from_file(game->mlx,
			"textures/floor.png", NULL, NULL);
	game->img_collectible = mlx_new_image_from_file(game->mlx,
			"textures/collectible.png", NULL, NULL);
	game->img_exit = mlx_new_image_from_file(game->mlx,
			"textures/exit.png", NULL, NULL);
}

void	free_images(t_game *game)
{
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
}
