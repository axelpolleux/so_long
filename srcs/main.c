/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:24:00 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/16 14:02:53 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include "libft/libft.h"
#include "so_long.h"

int	error(char *str)
{
	ft_putstr_fd("Error !\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("...\n", 2);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**map;

	i = 0;
	if (!main_parser(argc, argv, &map))
		return (1);
	while (map[i])
		printf("%s\n", map[i++]);
	free_map(map);
	return (0);
}
