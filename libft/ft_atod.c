/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:03:28 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/18 10:50:12 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atod(const char *str)
{
	double	result;
	int		i;

	i = 0;
	result = (double)ft_atoi(str);
	if (!str)
		return (0);
	while (str[i] != '.' && str[i] != '\0')
				++i;
	if (i && str[i])
	{
		if (result >= 0 && str[0] != '-')
			result += ((double)ft_atoi(str + i + 1))
				/ ((ft_strlen(str + i + 1) * 10));
		else
			result -= ((double)ft_atoi(str + i + 1))
				/ ((ft_strlen(str + i + 1) * 10));
	}
	return (result);
}
