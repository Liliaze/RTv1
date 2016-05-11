/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:16:45 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/14 10:53:17 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		go;
	int		end;
	int		i;

	go = 0;
	end = 0;
	i = 0;
	if (!s)
		return (NULL);
	while ((s[go] == ' ' || s[go] == '\n' || s[go] == '\t') && s[go])
		go++;
	while (s[end])
		end++;
	end--;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end >= 0)
		end--;
	if (!(new = (char *)malloc(sizeof(char) * (end <= go ? 1 : end - go + 2))))
		return (NULL);
	while (go <= end)
		new[i++] = s[go++];
	new[i] = '\0';
	return (new);
}
