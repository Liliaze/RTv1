/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:16:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/19 17:34:55 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

static void	define_target(t_cam *acam, t_v3d *target)
{
	*target = acam->origin;
	vector_translate(target, acam->dir_y, 10);
	vector_translate(target, acam->dir_x, -(WINW / 200));
	vector_translate(target, acam->dir_z, WINH / 200);
}

static void	define_rayon(t_v3d cur, t_ray *aray, t_cam *acam)
{
	aray->origin = acam->origin;
   	aray->dir.x = cur.x - aray->origin.x;
   	aray->dir.y = cur.y - aray->origin.y;
   	aray->dir.z = cur.z - aray->origin.z;
	aray->t = -1;
}

void	ray_tracing(t_all	*all)
{
	int		x;
	int		y;
	t_v3d	cur;
	double	coef_w;
	double	coef_h;

	coef_w = (double)WINW / ((double)WINW * 100);
	coef_h = (double)WINH / ((double)WINH * 100);
	define_target(all->acam, &cur);
	y = -1;
	while (++y < WINH)
	{
		x = -1;
		while (++x < WINW)
		{
			all->dist = -1;
			define_rayon(cur, all->aray, all->acam);
			smash_up(all);
			if (all->dist != -1)
				color_one_pixel_secure(all->color, all->aimg, x, y);
			vector_translate(&cur, all->acam->dir_x, coef_w);
		}
		vector_translate(&cur, all->acam->dir_x, -coef_w * WINW);
		vector_translate(&cur, all->acam->dir_z, -coef_h);
	}
}
