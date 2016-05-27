/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:16:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/27 19:20:47 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

static void	define_target(t_cam *acam, t_v3d *target)
{
	*target = acam->pos;
	vector_translate(target, acam->dir_y, 10);
	vector_translate(target, acam->dir_x, -(WINW / 200));
	vector_translate(target, acam->dir_z, WINH / 200);
}

static void	define_rayon(t_v3d target, t_ray *aray, t_cam *acam)
{
	aray->pos = acam->pos;
	aray->dir.x = target.x - aray->pos.x;
	aray->dir.y = target.y - aray->pos.y;
	aray->dir.z = target.z - aray->pos.z;
	vector_normalize(&aray->dir);
	aray->t = -1;
}

static int	check_spot(t_ray *aray, t_v3d *ai, t_spot *spot, t_obj *obj, int color) 
{
	t_spot	*tmp;
	t_obj	*tmp2;
	int		smash;
	int		color_def;

	tmp = spot;
	smash = 0;
	color_def = color;
	set_to(&aray->pos, ai);
	while (tmp)
	{
		set_to(&aray->dir, vector_sub(&tmp->pos, &aray->pos));
		vector_normalize(&aray->dir);
		tmp2 = obj;
		while (tmp2 && !smash)
		{
			smash = tmp2->smash(tmp2, aray);
			tmp2 = tmp2->next;
		}
		if (smash)
		{
			color_def = color * 0.5;
			break;
		}
		tmp = tmp->next;
	}
	return (color_def);
}

static void	smash_up(t_all *all)
{
	all->acur = all->aobj;
	while (all->acur)
	{
		all->acur->smash(all->acur, all->aray);
		if (((all->dist == -1) && all->aray->t > 0)
				|| (0 < all->aray->t && all->aray->t < all->dist))
		{
			all->dist = all->aray->t;
			all->color = all->acur->color;
			set_to(all->ai, &all->aray->i);
		}
		all->acur = all->acur->next;
	}
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
			{
				all->color = check_spot(all->aray, all->ai, all->aspot, all->aobj, all->color); 
				color_one_pixel_secure(all->color, all->aimg, xy[0], xy[1]);
			}
			vector_translate(&target, all->acam->dir_x, COEFW);
		}
		vector_translate(&target, all->acam->dir_x, -COEFW * (double)WINW);
		vector_translate(&target, all->acam->dir_z, -COEFH);
	}
}
