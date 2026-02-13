/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:09:59 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/13 12:15:51 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

static int	line_len_no_nl(const char *line)
{
	int	len;

	len = (int)ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}

int	check_border(char **map, int height, int width)
{
	int i;
	int j;
	int	len;

	i = 0;
	while (map[i])
	{
		j = 0;
		len = line_len_no_nl(map[i]);
		if (len != width)
			return (0);
		if (i == 0 || i == height - 1)
		{
			while (j < len)
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
		}
		else
		{
			if (map[i][0] != '1' || map[i][len - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}
