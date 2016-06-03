/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 10:35:09 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/03 14:20:22 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "color_key_mask.h"

static int	refresh_screen(t_all *all)
{
	if (!all->in_menu)
	{
		if (all->hook == 1)
		{
			all->hook = 0;
			ray_tracing(all);
		}
		mlx_clear_window(all->MLX, all->WIN);
		mlx_put_image_to_window(all->MLX, all->WIN, all->aimg->id, 0, 0);
	}
	return (0);
}

static int	key_press(int key, t_all *all)
{
	if (key == ECHAP || key == Q)
		exit(0);
	else if (key == DEL)
		color_all_pixel(BLACK, all->aimg->image, all->aimg->last_pixel);
	else if (key == W && (all->hook = 1))
		all->acam->pos.y += 5;
	else if (key == S && (all->hook = 1))
		all->acam->pos.y -= 5;
	else if (key == UP && (all->hook = 1))
		all->acam->dir_y.z += 0.08;
	else if (key == DOWN && (all->hook = 1))
		all->acam->dir_y.z -= 0.08;
	else if (key == LEFT && (all->hook = 1))
		all->acam->dir_y.x -= 0.08;
	else if (key == RIGHT && (all->hook = 1))
		all->acam->dir_y.x += 0.08;
	else if (key == MORE && (all->hook = 1))
		all->acam->pos.z += 8;
	else if (key == LESS && (all->hook = 1))
		all->acam->pos.z -= 8;
	else if (key == D && (all->hook = 1))
		all->acam->pos.x += 8;
	else if (key == A && (all->hook = 1))
		all->acam->pos.x -= 8;
	else if (key == ENTER || (key >= ONE && key <= FOUR))
		go_menu(all, key);
	return (0);
}

int			ft_loop(t_all *all)
{
	mlx_hook(all->awin->win, KEYPRESS, KEYPRESSM, key_press, all);
	mlx_loop_hook(all->awin->mlx, refresh_screen, all);
	mlx_loop(all->awin->mlx);
	return (0);
}
