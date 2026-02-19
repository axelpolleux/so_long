/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:23:49 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/19 18:06:48 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int	    count_lines(char *filepath);
int	    error(char *str);
int	    check_extension(char *str);
int	    main_parser(int argc, char **argv, char ***map);
int	    check_border(char **map, int height, int width);
int		counter(char **map, int character);
int		check_points(char **map);
void	free_map(char **map);
char	*get_line(int fd);
void	drain_gnl(int fd);
int		main_fill(char **map);
int		not_this_char(char **map, char *chars);
char	**copy_map(char **map);
void	get_coord(int *x, int *y, char find, char **map);

#endif
