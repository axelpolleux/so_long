/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolleux <apolleux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:24:00 by apolleux          #+#    #+#             */
/*   Updated: 2026/02/03 15:08:32 by apolleux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	error(char *str)
{
	printf("%s\n", str);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return (error("Only 1 argument (the .ber map file itself)"));
	if (!(&check_extension))
		return (error("Only .ber extensions accepted"));
}
