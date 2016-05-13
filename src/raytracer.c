/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:16:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/13 16:42:53 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include "libft.h"

void	init_camera(t_ray *aray, t_cam *acam, t_win *awin)
{
	acam->pos.x = 200; // utile ??? Verif a la fin
	acam->pos.y = 0; // idem
	acam->pos.z = 50; // idem
	aray->origin.x = 0;
	aray->origin.y = 0;
	aray->origin.z = 50;
	acam->res.x = awin->wwidth;
	acam->res.y = awin->wheight;
	acam->fov = 30;
	acam->dist_focale = -(acam->res.x / (2 * tan(acam->fov / 2)));
	//si seule fnt Math.h a precalc et virer la lib
	aray->target_pixel.z = acam->dist_focale;
	printf("[%f]\n", aray->target_pixel.z = acam->dist_focale); //TMP
}

void	define_pixel_target(int x, int y, t_cam *acam, t_ray *aray)
{
	aray->target_pixel.x = x - (acam->res.x / 2);
	aray->target_pixel.y = y - (acam->res.y / 2);
	//vector_normalize(&aray->target_pixel);
}

void	define_ray_dir(t_ray *aray)
{
   	aray->dir.x = aray->target_pixel.x - aray->origin.x;
   	aray->dir.y = aray->target_pixel.y - aray->origin.y;
   	aray->dir.z = aray->target_pixel.z - aray->origin.z;
	vector_normalize(&aray->dir);
}

void	ray_tracing(t_all	*all)
{
	int		x;
	int		y;
	double	t;
	int		color;
	double	t_cmp;
	t_obj	*lst_obj;

	init_sphere(all->aobj); //tmp, parsing a faire
	y = -1;
	while (++y < all->awin->wheight)
	{
		x = -1;
		while (++x < all->awin->wwidth)
		{
			lst_obj = all->aobj;
			t_cmp = MAX_DIST;
			color = BLACK;
			define_pixel_target(x, y, all->acam, all->aray); //Point visé
			define_ray_dir(all->aray); //vecteur directeur unitaire entre pos et target
			while (lst_obj)
			{
				t = MAX_DIST;
				if (smash(lst_obj, all->aray, &t))
					if (t < t_cmp)
					{
						t_cmp = t;
						color = lst_obj->color;
					}
				if (color != BLACK)
					color_one_pixel_secure(color, all->aimage, x, y);
				lst_obj = lst_obj->next;
			}
		}
	}
}
