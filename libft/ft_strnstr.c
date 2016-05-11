/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:04:27 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/04 09:06:58 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	if (s2[i1] == '\0')
		return ((char *)s1);
	while (s1[i1] && n >= i1)
	{
		while (s1[i1 + i2] == s2[i2] && s2[i2] && s1[i1 + i2])
			i2++;
		if (s2[i2] == '\0' && (i1 + i2) <= n)
			return (((char *)s1) + i1);
		i2 = 0;
		i1++;
	}
	return (NULL);
}
