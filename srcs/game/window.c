/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:49:36 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/01 18:53:22 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_event(int event, void *param)
{
	if (event == 0)
		close_manager(param);
}

static	int	check_screen_size(t_game *game, int w_map, int h_map)
{
	int	width = 0;
	int	height = 0;

	mlx_get_screen_size(game->mlx, game->win, &width, &height);
	if (h_map > height || w_map > width)
		return (error("Map overcomes screen size"));
	return (1);
} 

void	window(t_game *game, char *title, int x, int y)
{
	mlx_window_create_info	info;

	info = (mlx_window_create_info){0};
	info.title = title;
	info.width = x;
	info.height = y;
	game->win = mlx_new_window(game->mlx, &info);
	if (check_screen_size(game, x, y) == 0)
	{
		mlx_destroy_window(game->mlx, game->win);
		return ;
	}
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
