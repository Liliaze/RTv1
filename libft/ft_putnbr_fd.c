/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:37:38 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/07 15:12:41 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	char	c;
	long	sign;

	i = 1;
	sign = 1;
	c = '-';
	if (n < 0)
	{
		sign = -1;
		write(fd, &c, 1);
	}
	while (i <= (n * sign))
		i *= 10;
	if (i >= 10)
		i /= 10;
	while (i > 0)
	{
		c = ((n * sign) / i) + '0';
		write(fd, &c, 1);
		n = n % i;
		i /= 10;
	}
}
