/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:12:25 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/08 13:11:02 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_trace_c(unsigned int i, char c)
{
	ft_color("32");
	ft_putstr("trace char n°");
	ft_putnbr(i);
	ft_putstr(" = (");
	ft_putchar(c);
	ft_putstr(").\n");
	ft_color("37");
}
