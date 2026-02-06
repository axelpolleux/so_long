/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:38:20 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/06 21:02:27 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static int	count_lines(int fd)
{

}

static char	**map_maker(char *filepath)
{
	int		fd;
	int		i;
	char	**res;

	fd = open(filepath, O_RDONLY);

	while ()

	close(fd);
	return (res);
}

static int	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	close(fd);
	return (fd);
}

int	main_parser(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (error("Only 1 argument\n"));
	else if (ft_strlen(argv[1]) <= 4 || ft_strncmp(argv[1] + (ft_strlen(argv[1])
				- 4), ".ber", 4) != 0)
		return (error("Only .ber files\n"));
	else if (file_exists(argv[1]) == -1)
		return (error("File doesn't exist, or cannot be opened\n"));
	else
		map = map_maker(argv[1]);
	return (1);
}
