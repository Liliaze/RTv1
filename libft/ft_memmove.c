/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:58:23 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/12 11:28:25 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = (char *)src;
	s2 = (char *)dst;
	i = 0;
	if (s2 < s1)
	{
		while (len--)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	else if (s2 > s1)
	{
		i = len - 1;
		while (len--)
		{
			s2[i] = s1[i];
			i--;
		}
	}
	return (dst);
}
