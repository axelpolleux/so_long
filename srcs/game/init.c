/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:37:03 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/23 18:35:16 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	game_engine(char **map)
{
	t_game	game;

	(void)map;
	game.mlx = mlx_init();
	window(game, "Test du titre", 400, 400);
	mlx_destroy_context(game.mlx);
}
