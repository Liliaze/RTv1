/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:52:22 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/20 18:16:07 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_change_color(char *str)
{
	ft_putstr("\033[");
	ft_putstr(str);
}

void		ft_display_error(char *str)
{
	ft_putstr("\033[H\033[2J");
	ft_putstr("An error is encounter : '");
	ft_change_color("1;33m");
	ft_putstr(str);
	ft_change_color("0m");
	ft_putstr("'. Try again ;)");
	exit(1);
}
