/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:02:13 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/02 11:51:11 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

mlx_image	load(char *path, mlx_context mlx)
{
	int			fd;
	mlx_image	img;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	close(fd);
	img = mlx_new_image_from_file(mlx, path,
			NULL, NULL);
	return (img);
}

int	load_images(t_game *game)
{
	game->img_player = load("textures/player.png", game->mlx);
	game->img_wall = load("textures/wall.png", game->mlx);
	game->img_floor = load("textures/floor.png", game->mlx);
	game->img_collectible = load("textures/collectible.png", game->mlx);
	game->img_exit = load("textures/exit.png", game->mlx);
	if (!game->img_player || !game->img_wall || !game->img_floor
		|| !game->img_collectible || !game->img_exit)
	{
		return (error("All the sprites are not accessible !\n⤜(ⱺ ʖ̯ⱺ)⤏\n"));
	}
	return (1);
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
