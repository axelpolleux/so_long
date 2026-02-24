/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:49:36 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/24 09:58:20 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	window(t_game game, char *title, int size_x, int size_y)
{
	mlx_window_create_info	window_info;

	window_info.title = title;
	window_info.width = size_x;
	window_info.height = size_y;
	game.win = mlx_new_window(game.mlx, &window_info);
	mlx_destroy_window(game.mlx, game.win);
}
