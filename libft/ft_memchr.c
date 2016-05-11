/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:56:12 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/14 10:31:35 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)s;
	while (n--)
	{
		if ((unsigned char)c == s1[i])
			return (s1 + i);
		i++;
	}
	return (NULL);
}
