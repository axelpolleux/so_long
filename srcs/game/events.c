/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:02:17 by apolleux          #+#    #+#             */
/*   Updated: 2026/03/03 10:05:53 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

void	close_manager(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_loop_end((mlx_context)game->mlx);
}

static void	move_x(t_game *game, int key)
{
	int		pos_x;
	int		pos_y;
	char	**map;

	pos_x = game->player.pos_x;
	pos_y = game->player.pos_y;
	map = game->map;
	if (key == 79 && (map[pos_y][pos_x + 1] != '1'))
	{
		game->player.pos_x++;
		ft_printf("Gerard Movement: %d\r", game->player.movements++);
	}
	else if (key == 80 && (map[pos_y][pos_x - 1] != '1'))
	{
		game->player.pos_x--;
		ft_printf("Gerard Movement: %d\r", game->player.movements++);
	}
}

static void	move_y(t_game *game, int key)
{
	int		pos_x;
	int		pos_y;
	char	**map;

	pos_x = game->player.pos_x;
	pos_y = game->player.pos_y;
	map = game->map;
	if (key == 81 && (map[pos_y + 1][pos_x] != '1'))
	{
		game->player.pos_y++;
		ft_printf("Gerard Movement: %d\r", game->player.movements++);
	}
	else if (key == 82 && (map[pos_y - 1][pos_x] != '1'))
	{
		game->player.pos_y--;
		ft_printf("Gerard Movement: %d\r", game->player.movements++);
	}
}

void	key_manager(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 41)
		close_manager(param);
	else if (key >= 79 && key <= 80)
		move_x(game, key);
	else if (key >= 81 && key <= 82)
		move_y(game, key);
}
