/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:15:33 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/08 13:11:14 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_trace_i(unsigned int i, int nb)
{
	ft_color("34");
	ft_putstr("trace int n°");
	ft_putnbr(i);
	ft_putstr(" = ");
	ft_putnbr(nb);
	ft_putstr(".\n");
	ft_color("37");
}
