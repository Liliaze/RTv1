/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:16:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/19 18:04:14 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	define_target(t_cam *acam, t_v3d *target)
{
	*target = acam->origin;
	vector_translate(target, acam->dir_y, 10);
	vector_translate(target, acam->dir_x, -(WINW / 200));
	vector_translate(target, acam->dir_z, WINH / 200);
}

static void	define_rayon(t_v3d target, t_ray *aray, t_cam *acam)
{
	aray->origin = acam->origin;
   	aray->dir.x = target.x - aray->origin.x;
   	aray->dir.y = target.y - aray->origin.y;
   	aray->dir.z = target.z - aray->origin.z;
	aray->t = -1;
}

void	ray_tracing(t_all	*all)
{
	int		xy[2];
	t_v3d	target;

	define_target(all->acam, &target);
	xy[1] = -1;
	while (++xy[1] < WINH)
	{
		xy[0] = -1;
		while (++xy[0] < WINW)
		{
			all->dist = -1;
			define_rayon(target, all->aray, all->acam);
			smash_up(all);
			if (all->dist != -1)
				color_one_pixel_secure(all->color, all->aimg, xy[0], xy[1]);
			vector_translate(&target, all->acam->dir_x, COEFW);
		}
		vector_translate(&target, all->acam->dir_x, -COEFW * (double)WINW);
		vector_translate(&target, all->acam->dir_z, -COEFH);
	}
}
