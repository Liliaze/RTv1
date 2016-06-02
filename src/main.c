/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:29:58 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/01 11:19:35 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"

void init_cam(t_cam *acam)
{
	acam->pos.x = 0;
	acam->pos.y = -100;
	acam->pos.z = 0;
	acam->dir_x.x = 1;
	acam->dir_x.y = 0;
	acam->dir_x.z = 0;
	acam->dir_y.x = 0;
	acam->dir_y.y = 1;
	acam->dir_y.z = 0;
	acam->dir_z.x = 0;
	acam->dir_z.y = 0;
	acam->dir_z.z = 1;
}

inline static void	init_window_and_img(t_win *win, t_img *img, char *title)
{
	win->title = ft_strdup(title);
	win->width = WINW;
	win->height = WINH;
	img->width = WINW;
	img->height = WINH;
	if ((win->mlx = mlx_init()) == NULL)
		ft_display_error("mlx_init() does not function");
	if ((win->win = mlx_new_window(win->mlx, win->width, win->height,
					win->title)) == NULL)
		ft_display_error("mlx_new_window() does not function");
	if (!(img->id = mlx_new_image(win->mlx, img->width, img->height)))
		ft_display_error("mlx_new_image() does not function");
	if (!(img->image = mlx_get_data_addr(img->id, &img->bpp,
					&img->size_line, &img->endian)))
		ft_display_error("mlx_get_data_addr() does not function");
	img->bpp = (img->bpp / 8) / 4;
	img->size_line = img->size_line / 4;
	img->last_pixel = img->height * img->size_line;
}

inline static void	init_struct(t_all *all)
{
	all->awin = (t_win *)ft_memalloc(sizeof(t_win));
	all->aimg = (t_img *)ft_memalloc(sizeof(t_img));
	all->acam = (t_cam *)ft_memalloc(sizeof(t_cam));
	all->aray = (t_ray *)ft_memalloc(sizeof(t_ray));
	all->acur = (t_obj *)ft_memalloc(sizeof(t_obj));
	all->aobj = (t_obj *)ft_memalloc(sizeof(t_obj));
	all->aobj->type = ft_strdup("first");
	all->aspot = (t_spot *)ft_memalloc(sizeof(t_spot));
	all->aspot->type = ft_strdup("first");
	all->ai = (t_v3d *)ft_memalloc(sizeof(t_v3d));
}

int	main(int ac, char **av)
{
	t_all	*all;

	if (ac != 2)
		ft_display_error("Please join a scene");
	else
	{
		all = (t_all *)ft_memalloc(sizeof(t_all));
		init_struct(all);
		init_window_and_img(all->awin, all->aimg, av[1]);
		init_cam(all->acam);
		read_scene(all->aobj, all->aspot, all->acur, av[1]);
		//ajout menu et multi argument ?
		ft_loop(all);
	}
	return (0);
}
