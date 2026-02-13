/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:38:20 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/13 14:58:36 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"

static void	get_dimension(char *filepath, int *height, int *width)
{
	int		fd;
	char	*str;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		*height = -1;
		return ;
	}
	*height = 0;
	*width = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (*width > 0)
		{
			if (*width != (int)ft_strlen(str))
			{
				*width = -1;
				break ;
			}
		}
		*width = ft_strlen(str);
		*height += 1;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}

static char	**map_maker(char *filepath, int height)
{
	int		i;
	int		fd;
	char	**res;

	i = 0;
	fd = open(filepath, O_RDONLY);
	res = malloc(sizeof(char *) * (height + 1));
	while (i < height)
		res[i++] = get_next_line(fd);
	res[i] = NULL;
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
		return (error("Only .ber files"));
	else if (height <= 0)
		return (error("File doesn't exist, or is empty"));
	// else if (height < 3 || width < 3)
	//	return (error("map is too small"));
	else if (width < 0)
		return (error("Map is not rectangular"));
	*map = map_maker(argv[1], height);
	if (!check_border(*map, height, width))
		return (error("Map must be surrounded by walls"));
	printf("Hauteur: %d\nLargeur: %d\n", height, width);
	return (1);
}
