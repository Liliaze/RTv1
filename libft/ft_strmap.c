/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:51:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/14 10:40:07 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	i = 0;
	while (s[i])
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	s2[i] = '\0';
	i--;
	while (i >= 0)
	{
		s2[i] = f(s[i]);
		i--;
	}
	return (s2);
}
