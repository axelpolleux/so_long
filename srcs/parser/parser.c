/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:38:20 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/09 18:48:25 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"

static int	count_width(char *filepath)
{
	int	fd;
	int	len1;
	int	len2;

	(void)len1;
	(void)len2;
	fd = open(filepath, O_RDONLY);
	// while (get_next_line(fd))
	// {
	// 	if
	// }
	close(fd);
	return (1);
}

int	count_dimension(char *filepath)
{
	int	fd;
	int	len;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (-1);
	len = 0;
	while (get_next_line(fd))
		len++;
	close(fd);
	return (len);
}

static char	**map_maker(char *filepath, int height)
{
	int		i;
	int		fd;
	char	**res;

	i = 0;
	fd = open(filepath, O_RDONLY);
	res = malloc(sizeof(char *) * height);
	while (i < height)
	{
		res[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (res);
}

int	main_parser(int argc, char **argv, char ***map)
{
	int	height;
	int	width;

	height = count_lines(argv[1]);
	width = count_width(argv[1]);
	(void)map;
	if (argc != 2)
		return (error("Only 1 argument\n"));
	else if (ft_strlen(argv[1]) <= 4 || ft_strncmp(argv[1] + (ft_strlen(argv[1])
				- 4), ".ber", 4) != 0)
		return (error("Only .ber files\n"));
	else if (height == -1)
		return (error("File doesn't exist, or cannot be opened\n"));
	else if (width == -1)
		return (error("Map isn't rectangular\n"));
	else
		*map = map_maker(argv[1], height);
	return (1);
}
