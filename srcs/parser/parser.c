/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:38:20 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/13 18:57:46 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"

static int	get_dimension(char *filepath, int *height, int *width)
{
	int		fd;
	char	*str;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		*height = -1;
		return (error("Your file doesn't exist, or is empty\nskill issue"));
	}
	*height = 0;
	*width = 0;
	str = get_line(fd);
	while (str)
	{
		if (*width > 0)
		{
			if (*width != (int)ft_strlen(str))
			{
				*width = -1;
				return (error("I don't like maths, and it's not rectangular"));
			}
		}
		*width = ft_strlen(str);
		*height += 1;
		str = get_line(fd);
	}
	free(str);
	close(fd);
	if (*height <= 2 || *width <= 2)
		return (error("I can't breath !!!\nThis map is too small"));
	return (1);
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

	if (argc > 2)
		return (error("WOW calm down !!\nI just need one argument"));
	else if (argc < 2)
		return (error("Meh... You don't wanna talk ?\nGive me one argument"));
	if (!get_dimension(argv[1], &height, &width))
		return (0);
	if (ft_strlen(argv[1]) <= 4 || ft_strncmp(argv[1] + (ft_strlen(argv[1])
				- 4), ".ber", 4) != 0)
		return (error("Only .ber files"));
	*map = map_maker(argv[1], height);
	if (!check_border(*map, height, width) || !check_points(*map))
		return (0);
	printf("Hauteur: %d\nLargeur: %d\n", height, width);
	return (1);
}
