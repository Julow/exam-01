/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 10:41:01 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 12:42:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISLAND_H
# define ISLAND_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define MAL(t,l)	((t*)malloc(sizeof(t) * (l)))

# define BUFF_SIZE	(128)

/*
** reader.c
*/
char			**read_islands(char *file);

/*
** counter.c
*/
void			count_islands(char **islands);

/*
** printer.c
*/
void			print_islands(char **islands);

/*
** utils.c
*/
int				ft_strlen(char *str);
void			ft_stradd(char **str, char *add, int len);
void			ft_memfree(void **tab);
int				ft_memlen(void **tab);
void			ft_memadd(void ***tab, void *add);

#endif
