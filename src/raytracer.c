/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:16:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/18 19:03:55 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include "libft.h"

static void	define_target(t_v3d *target, t_cam *acam)
{
	target = vector_copy(&(acam->origin));
	vector_translate(target, &(acam->dir_y), 10.0);
	vector_translate(target, &(acam->dir_x), -(WINW / 200.0));
	vector_translate(target, &(acam->dir_z), WINH / 200.0);
}

static void	define_rayon(t_ray *aray, t_cam *acam, double *dist)
{
	aray->origin = acam->origin;
   	aray->dir.x = aray->target.x - aray->origin.x;
   	aray->dir.y = aray->target.y - aray->origin.y;
   	aray->dir.z = aray->target.z - aray->origin.z;
	aray->t = -1.000;
	*dist = -1.000;
}

void	ray_tracing(t_all	*all)
{
	int		x;
	int		y;
	double	coef_w;
	double	coef_h;

	coef_w = WINW / (WINW * 100.0);
	coef_h = WINH / (WINH * 100.0);
	define_target(&(all->aray->target), all->acam);
	y = -1;
	while (++y < WINH)
	{
		x = -1;
		while (++x < WINW)
		{
			define_rayon(all->aray, all->acam, &(all->dist));
			smash_check(all);
			if (all->dist < -1 || all->dist > -1)
				color_one_pixel_secure(all->color, all->aimg, x, y);
			vector_translate(&(all->aray->target), &(all->acam->dir_x), coef_w);
		}
		vector_translate(&(all->aray->target), &(all->acam->dir_x), coef_w);
		vector_translate(&(all->aray->target), &(all->acam->dir_x), coef_w);
	}
}
