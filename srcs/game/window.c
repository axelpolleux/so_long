/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:49:36 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/24 12:50:01 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_event(int event, void *param)
{
	printf("Window event: %d\n", event);
	if (event == 0)
		close_manager(param);
}

void	window(t_game *game, char *title, int size_x, int size_y)
{
	mlx_window_create_info	info;

	info = (mlx_window_create_info){0};
	info.title = title;
	info.width = size_x;
	info.height = size_y;
	game->win = mlx_new_window(game->mlx, &info);
	mlx_on_event(game->mlx, game->win, MLX_WINDOW_EVENT, win_event, game->mlx);
	mlx_on_event(game->mlx, game->win, MLX_KEYDOWN, key_manager, game->mlx);
	main_scene(game);
	mlx_loop(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
}
