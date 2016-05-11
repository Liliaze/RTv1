/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:49:16 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/14 10:30:01 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_itoa(int n)
{
	int		nb;
	int		i;
	int		sign;
	char	*new;

	nb = n;
	i = 1;
	sign = 1;
	if (nb < 0 && i++)
		sign = -1;
	while ((nb = nb / 10) != 0)
		i++;
	if ((new = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	new[i] = '\0';
	while (i-- > 0)
	{
		new[i] = (n % 10 * sign) + '0';
		n = n / 10;
	}
	if (sign == -1)
		new[0] = '-';
	return (new);
}
