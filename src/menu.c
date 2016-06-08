/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 10:27:46 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/08 17:05:59 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"

static void	draw_name_map(t_win *awin)
{
	int	i;
	char *stri;
	char *tmp1;
	char *tmp2;

	i = 1;

	while (i < awin->ac)
	{
		stri = ft_itoa(i);
		tmp1 = ft_strjoin(" == ", MAP[i]);
		tmp2 = ft_strjoin(stri, tmp1);
		i++;
		mlx_string_put(MLX, WIN, (WINW - (int)(ft_strlen(tmp2) * 10)) / 2,
				(WINH - 30) / 2 + 30 * i, BLUEF, tmp2);
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
		ft_strdel(&stri);
	}
}

static void	draw_str_menu(t_win *awin)
{
	mlx_string_put(MLX, WIN, (WINW - 210) / 2,
			50, RED, "WELCOME IN MY RTV1 :D");
	mlx_string_put(MLX, WIN, (WINW - 610) / 2, 75, RED,
			"================= * ENTER YOUR NUMBER MAP * =================");
	mlx_string_put(MLX, WIN, (WINW - 370) / 2, WINH - 110,
			BLACK, "WASD to move the camera on axe x or z");
	mlx_string_put(MLX, WIN, (WINW - 350) / 2, WINH - 85,
			BLACK, "Use + or - to up or down the camera");
	mlx_string_put(MLX, WIN, (WINW - 280) / 2, WINH - 60,
			BLACK, "ARROWS to inclined the camera");
	mlx_string_put(MLX, WIN, (WINW - 180) / 2, WINH - 35,
			GREY, "ECHAP or Q to quit");
}

void		go_menu(t_all *all, int key)
{
	
	if (key == ENTER && !all->in_menu)
	{
		if (ft_strcmp(all->aobj->type, "first"))
			free_scene(all->aobj, all->aspot, all->nb_o, all->nb_s);
		free(all->scene);
		all->in_menu = 1;
		init_cam(all->acam);
		all->scene = ft_strdup("map/menu.txt");
		read_scene(all);
		ray_tracing(all);
		mlx_clear_window(all->MLX, all->WIN);
		mlx_put_image_to_window(all->MLX, all->WIN, all->aimg->id, 0, 0);
		draw_str_menu(all->awin);
		draw_name_map(all->awin);
	}
	else if (key != ENTER && all->in_menu)
	{
		if (key - 82 < all->awin->ac && key -82 >= 1)
		{
			free(all->scene);
			free_scene(all->aobj, all->aspot, all->nb_o, all->nb_s);
			all->scene = ft_strdup(all->MAP[key - 82]);
			init_cam(all->acam);
			read_scene(all);
			all->in_menu = 0;
			all->hook = 1;
		}
		else
			mlx_string_put(all->MLX, all->WIN, (WINW - 420) / 2,
				95, YELLOW, "Enter a number in the list of map - Try Again");
	}
}

