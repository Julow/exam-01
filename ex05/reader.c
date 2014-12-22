/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:42:23 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:50:02 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"

static char		**split_lines(char *str)
{
	char			*line;
	char			**lines;
	int				i;
	int				tmp;

	lines = MAL(char*, 1);
	lines[0] = NULL;
	tmp = 0;
	i = -1;
	while (str[++i] != '\0')
		if (str[i] == '\n' || str[i + 1] == '\0')
		{
			line = MAL(char, 1);
			line[0] = '\0';
			ft_stradd(&line, str + tmp, i - tmp);
			ft_memadd((void***)&lines, line);
			tmp = i + 1;
		}
	return (lines);
}

static void		read_lines(char ***islands, int fd)
{
	char			*content;
	char			*buff;
	int				len;

	content = MAL(char, 1);
	content[0] = '\0';
	buff = MAL(char, BUFF_SIZE);
	while ((len = read(fd, buff, BUFF_SIZE)) > 0)
		ft_stradd(&content, buff, len);
	free(buff);
	*islands = split_lines(content);
}

static int		check_islands(char **islands)
{
	int				i;
	int				j;
	int				line_len;

	if (*islands == NULL)
		return (0);
	line_len = ft_strlen(*islands);
	if (line_len > 1024)
		return (0);
	i = -1;
	while (islands[++i] != NULL)
	{
		j = -1;
		while (islands[i][++j] != '\0')
			if (islands[i][j] != 'X' && islands[i][j] != '.')
				return (0);
		if (j != line_len)
			return (0);
	}
	return (1);
}

char			**read_islands(char *file)
{
	int				fd;
	char			**islands;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	islands = MAL(char*, 1);
	islands[0] = NULL;
	read_lines(&islands, fd);
	close(fd);
	if (!check_islands(islands))
	{
		ft_memfree((void**)islands);
		islands = NULL;
	}
	return (islands);
}
