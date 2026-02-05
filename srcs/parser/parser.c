/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:38:20 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/05 17:13:20 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <stdio.h>

static char	**get_lines(int fd)
{
	char	**res;
	char	*line;

	(void)res;
	res = NULL;
	line = NULL;
	while (line == get_next_line(fd))
	{
		printf("%s", line);
	}
	return (res);
}

static int	file_exists(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (0);
	close(*fd);
	return (1);
}

int	main_parser(int argc, char **argv)
{
	int	fd;

	(void)argv;
	if (argc != 2)
		return (error("Only 1 argument\n"));
	else if (ft_strlen(argv[1]) <= 4 || ft_strncmp(argv[1] + (ft_strlen(argv[1])
				- 4), ".ber", 4) != 0)
		return (error("Only .ber files\n"));
	else if (!file_exists(argv[1], &fd))
		return (error("File doesn't exist, or cannot be opened\n"));
	else
		get_lines(fd);
	return (1);
}
