/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 10:35:09 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/19 16:20:24 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "libft.h"
#include "color_key_mask.h"
/*
static int	refresh_screen(t_all *all)
{
	mlx_clear_window(all->awin->mlx, all->awin->win);
	mlx_put_image_to_window(all->awin->mlx, all->awin->win,
			all->aimg->id, 0, 0);
	return (0);
}
*/
static int	key_press(int key, t_all *all)
{
	if (key == ECHAP)
		exit(0);
	if (key == DEL)
		color_all_pixel(BLACK, all->aimg->image, all->aimg->last_pixel);
	if (key == UP)
	{
		mlx_clear_window(all->awin->mlx, all->awin->win);
		mlx_put_image_to_window(all->awin->mlx, all->awin->win,
				all->aimg->id, 0, 0);
		ft_putstr("nothing to make on touch UP...\n");
	}
	return (0);
}

int			ft_loop(t_all *all)
{
	mlx_hook(all->awin->win, KEYPRESS, KEYPRESSM, key_press, all);
//	mlx_loop_hook(all->awin->mlx, refresh_screen, all);
	mlx_loop(all->awin->mlx);
	return (0);
}
