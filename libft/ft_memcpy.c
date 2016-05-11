/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:41:26 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/11 14:44:37 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = (unsigned char*)dst;
	s2 = (const unsigned char*)src;
	while (n-- > 0)
		s1[n] = s2[n];
	return (dst);
}
