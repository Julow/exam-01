/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:39:53 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:40:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"

int				main(int argc, char **argv)
{
	char			**islands;

	if (argc > 1)
	{
		islands = read_islands(argv[1]);
		if (islands != NULL)
		{
			count_islands(islands);
			print_islands(islands);
			return (0);
		}
	}
	write(1, "\n", 1);
	return (0);
}
