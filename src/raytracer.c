/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:16:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/11 17:47:49 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>


void	init_camera(t_cam *acam, t_win *awin)
{
	acam->pos.x = 0;
	acam->pos.y = 0;
	acam->pos.z = 0;
	acam->res.x = awin->wwidth;
	acam->res.y = awin->wheight;
	acam->fov = 30;
	acam->dist_focale = -(acam->res.x / (2 * tan(acam->fov / 2)));
	acam->target_pixel.z = acam->dist_focale;
	printf("[%f]\n", acam->target_pixel.z = acam->dist_focale); //TMP
}

void	define_pixel_target(int x, int y, t_cam *acam)
{
	acam->target_pixel.x = x - (acam->res.x / 2);
	acam->target_pixel.y = y - (acam->res.y / 2);
	vector_normalize(acam->target_pixel);
}

void	define_ray_dir(t_cam *acam)
{
   	acam->ray_dir.x = acam->target_pixel.x - acam->pos.x; // ici pos = 0 donc variables peut-etre inutile a voir a la fin.
   	acam->ray_dir.y = acam->target_pixel.y - acam->pos.y;
   	acam->ray_dir.z = acam->target_pixel.z - acam->pos.z;
	vector_normalize(acam->ray_dir);
}

void	ray_tracing(t_all	*all)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < all->awin->wheight)
	{
		while (++x < all->awin->wwidth)
		{
			 define_pixel_target(x, y, all->acam); //Point visé
			 define_ray_dir(all->acam); //vecteur directeur unitaire entre pos et target
			 //intersect objet ???? A Ecrire.
		}
	}
}
