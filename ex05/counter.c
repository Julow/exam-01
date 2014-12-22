/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:49:05 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:49:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"

static void		num_islands(char **islands, int i, int j, int n)
{
	if (islands[i] != NULL && islands[i][j] == 'X')
	{
		islands[i][j] = '0' + (n % 10);
		num_islands(islands, i + 1, j, n);
		if (i > 0)
			num_islands(islands, i - 1, j, n);
		num_islands(islands, i, j + 1, n);
		if (j > 0)
			num_islands(islands, i, j - 1, n);
	}
}

void			count_islands(char **islands)
{
	int				i;
	int				j;
	int				count;

	count = 0;
	i = -1;
	while (islands[++i] != NULL)
	{
		j = -1;
		while (islands[i][++j] != '\0')
			if (islands[i][j] == 'X')
			{
				num_islands(islands, i, j, count);
				count++;
			}
	}
}
