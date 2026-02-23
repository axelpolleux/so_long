/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:23:49 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/23 14:53:39 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// ____________________
// <<<<<< INCLUDES >>>>>
// ^^^^^^^^^^^^^^^^^^^^
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// ___________________
// <<<<<< TYPES >>>>>>>
// ^^^^^^^^^^^^^^^^^^^
typedef struct s_player
{
	int	can_exit;
	int	pos_x;
	int	pos_y;
}	t_player;

// __________________
// <<<<<< MAIN >>>>>>>
// ^^^^^^^^^^^^^^^^^^
int		error(char *str);

// ____________________
// <<<<<< PARSER >>>>>>>
// ^^^^^^^^^^^^^^^^^^^^
int		main_parser(int argc, char **argv, char ***map);

// file management
int		check_extension(char *str);
int		count_lines(char *filepath);

// memory management
char	**copy_map(char **map);
void	free_map(char **map);

// map management
char	*get_line(int fd);
int		check_border(char **map, int height, int width);
void	drain_gnl(int fd);
int		main_fill(char **map);

// objects management
int		counter(char **map, int character);
void	get_coord(int *x, int *y, char find, char **map);
int		check_points(char **map);
int		not_this_char(char **map, char *chars);

// __________________
// <<<<<< GAME >>>>>>>
// ^^^^^^^^^^^^^^^^^^
void	game_engine(char **map);
void	create_window(mlx_context mlx);
#endif
