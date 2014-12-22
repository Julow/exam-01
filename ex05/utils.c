/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:44:43 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:02:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "island.h"

int				ft_strlen(char *str)
{
	int				len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void			ft_stradd(char **str, char *add, int len)
{
	char			*tmp;
	int				i;
	int				j;

	tmp = MAL(char, ft_strlen(*str) + len + 1);
	i = -1;
	while ((*str)[++i] != '\0')
		tmp[i] = (*str)[i];
	free(*str);
	j = -1;
	while (++j < len)
		tmp[i++] = add[j];
	tmp[i] = '\0';
	*str = tmp;
}

void			ft_memfree(void **tab)
{
	int				i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}

int				ft_memlen(void **tab)
{
	int				len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

void			ft_memadd(void ***tab, void *add)
{
	int				len;
	void			**dst;

	len = ft_memlen(*tab);
	dst = malloc(sizeof(void*) * (len + 2));
	dst[len] = add;
	dst[len + 1] = NULL;
	while (len-- > 0)
		dst[len] = (*tab)[len];
	free(*tab);
	*tab = dst;
}
