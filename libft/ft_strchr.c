/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:57:23 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/05 17:07:15 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (tmp[i])
	{
		if (tmp[i] == c)
			return (tmp + i);
		i++;
	}
	if (c == '\0')
		return (tmp + i);
	return (NULL);
}
