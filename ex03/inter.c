/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:35:32 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 09:49:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strchri(char *str, char c)
{
	int			i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == c)
			return (i);
	return (-1);
}

int			main(int argc, char **argv)
{
	int			i;

	if (argc == 3)
	{
		i = -1;
		while (argv[1][++i] != '\0')
		{
			if (ft_strchri(argv[2], argv[1][i]) >= 0 && ft_strchri(argv[1],
				argv[1][i]) == i)
				write(1, argv[1] + i, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
