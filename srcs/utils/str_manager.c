/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:09:21 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/13 17:45:45 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "so_long.h"

char	*get_line(int fd)
{
	int		limit;
	char	*tmp;
	char	*res;

	tmp = get_next_line(fd);
	limit = ft_strichr(tmp, '\n');
	if (limit == -1)
		return (tmp);
	res = ft_substr(tmp, 0, limit);
	free(tmp);
	return (res);
}
