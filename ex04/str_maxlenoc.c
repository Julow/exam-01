/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:51:51 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 10:36:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char		*ft_strstrn(char *s1, char *s2, int n)
{
	int			j;

	while (*s1 != '\0')
	{
		j = 0;
		while (s2[j] != '\0' && j < n && s1[j] == s2[j])
			j++;
		if (j == n)
			return (s1);
		s1++;
	}
	return (NULL);
}

static int		ft_strlen(char *str)
{
	int				len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static int		ft_contains(char **strs, int count, char *s, int len)
{
	int				i;

	i = -1;
	while (++i < count)
		if (ft_strstrn(strs[i], s, len) == NULL)
			return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	int				i;
	int				len;

	len = (argc > 1) ? ft_strlen(argv[1]) : 0;
	while (len > 0)
	{
		i = 0;
		while (argv[1][i + len - 1] != '\0')
		{
			if (ft_contains(argv + 1, argc - 1, argv[1] + i, len))
			{
				write(1, argv[1] + i, len);
				break ;
			}
			i++;
		}
		if (argv[1][i + len - 1] != '\0')
			break ;
		len--;
	}
	write(1, "\n", 1);
	return (0);
}
