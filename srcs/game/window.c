/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:49:36 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/23 15:04:40 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	create_window(mlx_context mlx)
{
	mlx_window_create_info	window_info;
	mlx_window				win;
	
	window_info = {0};
	window_info.title = "So Long";
	window_info.width = 
}