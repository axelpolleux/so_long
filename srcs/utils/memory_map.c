/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:44:04 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/17 19:21:20 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

//void	get_coord(int *x, int *y, char **map, char character)
//{
//	int	i;
//	int	j;

//	i = 0;
//	while(map[i])
//	{

//	}
//}

char	**copy_map(char **map, int height)
{
	char	**res;
	int		i;

	(void)height;
	res = ft_calloc(sizeof(char *), height + 1);
	i = 0;
	while (map[i])
	{
		res[i] = ft_strdup(map[i]);
		i++;
	}
	return (res);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
