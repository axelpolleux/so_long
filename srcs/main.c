/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:24:00 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/20 19:09:15 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	error(char *str)
{
	ft_putstr_fd("Error !\n", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (!main_parser(argc, argv, &map))
		return (1);
	else
		game_engine(map);
	free_map(map);
	return (0);
}
