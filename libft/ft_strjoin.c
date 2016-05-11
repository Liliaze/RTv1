/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:30:40 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/14 10:39:08 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		while (s1[i])
			i++;
		while (s2[j])
			j++;
		new = (char *)malloc(sizeof(char *) * (i + j + 1));
		if (!new)
			return (NULL);
		new[i + j] = s2[j];
		while (--j >= 0)
			new[i + j] = s2[j];
		j = 0;
		while (--i >= 0)
			new[i] = s1[i];
		return (new);
	}
	return (NULL);
}
