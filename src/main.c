/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:29:58 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/11 17:47:52 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"

inline static void	init_window_and_img(t_win *win, t_image *img, char *title)
{
	win->title_win = ft_strdup(title);
	win->wwidth = 1280;
	win->wheight = 800;
	img->iwidth = 1280;
	img->iheight = 800;
	if ((win->mlx = mlx_init()) == NULL)
		ft_display_error("mlx_init() does not function");
	if ((win->win = mlx_new_window(win->mlx, win->wwidth, win->wheight,
				win->title_win)) == NULL)
		ft_display_error("mlx_new_window() does not function");
	if (!(img->id = mlx_new_image(win->mlx, img->iwidth, img->iheight)))
		ft_display_error("mlx_new_image() does not function");
	if (!(img->image = mlx_get_data_addr(img->id, &img->bpp,
					&img->size_line, &img->endian)))
		ft_display_error("mlx_get_data_addr() does not function");
	img->bpp = (img->bpp / 8) / 4;
	img->size_line = img->size_line / 4;
	img->last_pixel = img->iheight * img->size_line;
}

inline static void	init_struct(t_all *all)
{
	all->awin = (t_win *)ft_memalloc(sizeof(t_win));
	all->aimage = (t_image *)ft_memalloc(sizeof(t_image));
	all->acam = (t_cam *)ft_memalloc(sizeof(t_cam));
	all->apixel = (t_pixel *)ft_memalloc(sizeof(t_pixel));
	all->aobj = (t_obj *)ft_memalloc(sizeof(t_obj));
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
		init_window_and_img(all->awin, all->aimage, av[1]);
		init_camera(all->acam, all->awin); //emplacement test-tmp.
		// lire et parser les infos de la scene ici.
		// initiliaser les eventuels variables d'en en csq.
		ft_loop(all); /* appel de la boucle event */
	}
	return (0);
}
