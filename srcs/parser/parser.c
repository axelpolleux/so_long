/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:38:20 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/03 12:10:24 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <string.h>

int	check_extension(char *str)
{
	int	size;

	size = strlen(str);
	if (size <= 4)
		return (0);
	return (1);
}
