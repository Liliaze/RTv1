/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:47:51 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/14 13:32:07 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	char	*tmp;
	int		i;

	tmp = dst;
	i = 0;
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = src[i];
	return (dst);
}
