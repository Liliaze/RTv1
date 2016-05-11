/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:49:24 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/07 11:34:22 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	len;
	size_t	len2;
	int		available;

	i = 0;
	while (dst[i])
		i++;
	len = i;
	i = -1;
	available = size - len;
	while (src[++i] && available-- > 1)
		dst[len + i] = src[i];
	dst[len + i] = '\0';
	len2 = 0;
	while (len2 < len && len2 < size)
		len2++;
	i = 0;
	while (src[i])
		i++;
	return (len2 + i);
}
