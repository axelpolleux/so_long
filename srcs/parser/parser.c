/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:38:20 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/23 11:15:41 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"

static int	dimension_loop(int fd, int *height, int *width)
{
	char	*str;

	while (1)
	{
		str = get_line(fd);
		if (!str)
			break ;
		if (*width != 0 && *width != (int)ft_strlen(str))
		{
			free(str);
			drain_gnl(fd);
			close(fd);
			*width = -1;
			return (0);
		}
		*width = (int)ft_strlen(str);
		*height += 1;
		free(str);
	}
	return (1);
}

static int	get_dimension(char *filepath, int *height, int *width)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File doesn't exist or is not accessible\n", 2);
		return (error("skill issue ☉ ‿ ⚆ "));
	}
	*height = 0;
	*width = 0;
	if (dimension_loop(fd, height, width) == 0)
		return (error("I don't like maths, and it's not rectangular"));
	close(fd);
	if (*height == 0)
		return (error("(◔_◔) An empty map ?\ninteresting"));
	if (*height <= 2 || *width <= 2)
		return (error("╚(•⌂•)╝I can't breath !!!\nThis map is too small"));
	return (1);
}

static int	fill_map(char **res, int fd, int height)
{
	int	i;

	i = 0;
	while (res && i < height)
	{
		res[i] = get_line(fd);
		if (!res[i])
		{
			res[i] = NULL;
			free_map(res);
			close(fd);
			return (0);
		}
		i++;
	}
	return (1);
}

static char	**map_maker(char *filepath, int height)
{
	int		fd;
	char	**res;

	fd = open(filepath, O_RDONLY);
	res = ft_calloc(sizeof(char *), height + 1);
	if (fd == -1 || !res)
	{
		free(res);
		close(fd);
		return (NULL);
	}
	if (!fill_map(res, fd, height))
		return (0);
	close(fd);
	return (res);
}

int	main_parser(int argc, char **argv, char ***map)
{
	int	height;
	int	width;

	if (argc > 2)
		return (error("ヽ༼ຈʖ̯ຈ༽ﾉ\nWOW calm down !!\nI just need one argument"));
	else if (argc < 2)
		return (error("You don't wanna talk ?\n⊙ω⊙\nGive me one argument"));
	if (ft_strlen(argv[1]) <= 4 || ft_strncmp(argv[1] + (ft_strlen(argv[1])
				- 4), ".ber", 4) != 0)
		return (error("x⸑x how can you miss it ?\nOnly .ber files"));
	if (!get_dimension(argv[1], &height, &width))
		return (0);
	*map = map_maker(argv[1], height);
	if (!*map)
		return (error("Malloc failed while reading map"));
	if (!check_border(*map, height, width) || !check_points(*map)
		|| !not_this_char(*map, "10CPE") || !main_fill(*map))
	{
		free_map(*map);
		*map = NULL;
		return (0);
	}
	return (1);
}
