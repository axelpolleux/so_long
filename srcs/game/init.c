/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:37:03 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/23 14:51:18 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	game_engine(char **map)
{
	mlx_context				mlx;

	(void)map;
	mlx = mlx_init();

	mlx_destroy_context(mlx);
}
