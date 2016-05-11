/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:13:41 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/07 16:29:03 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int		i;
	int		len;

	i = -1;
	len = n;
	while (src[++i] && len-- > 0)
		dst[i] = src[i];
	while (len-- > 0)
		dst[i++] = '\0';
	return (dst);
}
