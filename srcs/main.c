/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:24:00 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/10 18:08:21 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int	error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	i = 0;
	if (!main_parser(argc, argv, &map))
		return (0);
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	return (0);
}
