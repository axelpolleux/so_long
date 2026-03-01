/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:49:36 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/01 16:49:34 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_event(int event, void *param)
{
	if (event == 0)
		close_manager(param);
}

void	window(t_game *game, char *title, int x, int y)
{
	mlx_window_create_info	info;

	info = (mlx_window_create_info){0};
	info.title = title;
	info.width = x;
	info.height = y;
	game->win = mlx_new_window(game->mlx, &info);
	mlx_on_event(game->mlx, game->win, MLX_WINDOW_EVENT, win_event, game);
	mlx_on_event(game->mlx, game->win, MLX_KEYDOWN, key_manager, game);
	if (load_images(game))
	{
		display_map(game);
		mlx_add_loop_hook(game->mlx, update, game);
		mlx_loop(game->mlx);
	}
	free_images(game);
	mlx_destroy_window(game->mlx, game->win);
}
