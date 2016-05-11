/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:25:49 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/04 16:12:27 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (n--)
	{
		if (s1[i] != s2[i] || s2[i] == '\0' || s1[i] == '\0')
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		i++;
	}
	return (0);
}
