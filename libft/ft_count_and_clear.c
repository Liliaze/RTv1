/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_and_clear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:44:42 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/10 14:11:00 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_and_clear(char *dest, char const *src, char c)
{
	int		word;
	int		i;
	int		j;

	j = 0;
	i = 0;
	word = 1;
	while (src[i])
	{
		while (src[i] == c && src[i])
			i++;
		if (src[i] != c && src[i])
			word++;
		while (src[i] != c && src[i])
			dest[j++] = src[i++];
		if (src[i] == c)
			dest[j++] = src[i++];
	}
	while (j <= i)
		dest[j++] = '\0';
	return (word);
}
