/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 09:27:13 by exam              #+#    #+#             */
/*   Updated: 2014/12/18 09:31:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
{
	int			i;
	char		*dst;

	i = 0;
	while (src[i] != '\0')
		i++;
	dst = (char*)malloc(sizeof(char) * (i + 1));
	if (dst == NULL)
		return (NULL);
	dst[i] = '\0';
	while (i-- > 0)
		dst[i] = src[i];
	return (dst);
}
