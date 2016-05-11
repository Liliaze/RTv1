/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:54:20 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/11 10:06:15 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	nb_word(const char *str, char c)
{
	int		len;

	len = 1;
	while (str)
	{
		str = ft_strchr(str, c);
		while (str && *str == c)
			++str;
		if (!str || !*str)
			return (len);
		++len;
	}
	return (len);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		len;
	char	*tmp;
	char	**save;

	if (!s || !*s)
		return (NULL);
	while (*s == c && *s)
		++s;
	if (!*s)
		return (ft_memalloc(sizeof(char*)));
	len = nb_word(s, c) + 1;
	tab = (char **)ft_memalloc(sizeof(char *) * len);
	save = tab;
	while (--len)
	{
		tmp = ft_strchr(s, c);
		if (!tmp && (*(tab++) = ft_strdup(s)))
			break ;
		*(tab++) = ft_strsub(s, 0, tmp - s);
		while (*tmp == c)
			++tmp;
		s = tmp;
	}
	return (save);
}
