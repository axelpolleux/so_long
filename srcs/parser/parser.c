/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:38:20 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/10 12:20:04 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"

// static int	check_border(void)
// {
// 	return (1);
// }

void	get_dimension(char *filepath, int *height, int *width)
{
	int		fd;
	int		height_res;
	int		width_res;
	char	*str;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		*height = -1;
		return ;
	}
	height_res = 0;
	width_res = 0;
	str = "";
	while (str)
	{
		str = get_next_line(fd);
		height_res++;
	}
	*height = height_res - 1;
	*width = width_res;
	close(fd);
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

	get_dimension(argv[1], &height, &width);
	if (argc != 2)
		return (error("Only 1 argument\n"));
	else if (ft_strlen(argv[1]) <= 4 || ft_strncmp(argv[1] + (ft_strlen(argv[1])
				- 4), ".ber", 4) != 0)
		return (error("Only .ber files\n"));
	else if (height <= 0)
		return (error("File doesn't exist, cannot be opened, or file is empty\n"));
	*map = map_maker(argv[1], height);
	printf("Hauteur: %d\nLargeur: %d\n", height, width);
	return (1);
}
