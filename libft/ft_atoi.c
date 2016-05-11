/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:29:35 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/15 19:48:37 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int nb;
	int sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (!(*str) || !str)
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' ||
				str[i] == '\t' || str[i] == '\v' || str[i] == '\f'))
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		nb = (nb * 10) + (str[i] - '0');
		++i;
	}
	return (nb * sign);
}
