/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:02:17 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/25 18:17:50 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_manager(void *param)
{
	mlx_loop_end((mlx_context)param);
}

void	key_manager(int key, void *param)
{
	if (key == 41)
		close_manager(param);
	printf("KeyDown: %d\n", key);
}
