/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 10:35:09 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/02 14:17:13 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "libft.h"
#include "color_key_mask.h"

static int	refresh_screen(t_all *all)
{
	mlx_clear_window(all->awin->mlx, all->awin->win);
	mlx_put_image_to_window(all->awin->mlx, all->awin->win,
			all->aimg->id, 0, 0);
	return (0);
}

static int	key_press(int key, t_all *all)
{
	if (key == ECHAP || key == Q)
		exit(0);
	if (key == DEL)
		color_all_pixel(BLACK, all->aimg->image, all->aimg->last_pixel);
	if (key == ENTER)
		init_cam(all->acam);
	if (key == W)
		all->acam->pos.y += 5;
	if (key == S)
		all->acam->pos.y -= 5;
	if (key == UP)
		all->acam->dir_y.z += 0.08;
	if (key == DOWN)
		all->acam->dir_y.z -= 0.08;
	if (key == LEFT)
		all->acam->dir_y.x -= 0.08;
	if (key == RIGHT)
		all->acam->dir_y.x += 0.08;
	if (key == MORE)
		all->acam->pos.z += 8;
	if (key == LESS)
		all->acam->pos.z -= 8;
	if (key == D)
		all->acam->pos.x += 8;
	if (key == A)
		all->acam->pos.x -= 8;
	if (key != DEL)
	{
		color_all_pixel(BLACK, all->aimg->image, all->aimg->last_pixel);
		ray_tracing(all);
	}
	return (0);
}

int			ft_loop(t_all *all)
{
	mlx_hook(all->awin->win, KEYPRESS, KEYPRESSM, key_press, all);
	mlx_loop_hook(all->awin->mlx, refresh_screen, all);
	mlx_loop(all->awin->mlx);
	return (0);
}
