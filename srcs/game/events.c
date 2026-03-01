/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:02:17 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/01 16:02:40 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_manager(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_loop_end((mlx_context)game->mlx);
}

void	key_manager(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 41)
		close_manager(param);
	else if (key == 79)
		game->player.pos_x++;
	else if (key == 80)
		game->player.pos_x--;
	else if (key == 81)
		game->player.pos_y++;
	else if (key == 82)
		game->player.pos_y--;
	printf("KeyDown: %d\n", key);
}
