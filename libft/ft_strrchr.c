/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:21:49 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/07 12:24:09 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (tmp[i])
		i++;
	if (c == '\0')
		return (tmp + i);
	while (i >= 0)
	{
		if (tmp[i] == c)
			return (tmp + i);
		i--;
	}
	return (NULL);
}
