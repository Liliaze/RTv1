/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:16:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/02 15:50:36 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

static void	define_target(t_cam *acam, t_v3d *target)
{
	set_to(target, &acam->pos);
	vector_translate(target, acam->dir_y, 10);
	vector_translate(target, acam->dir_x, -(WINW / 200));
	vector_translate(target, acam->dir_z, WINH / 200);
}

static void	define_rayon(t_v3d *target, t_ray *aray, t_cam *acam)
{
	set_to(&aray->pos, &acam->pos);
	aray->dir.x = target->x - aray->pos.x;
	aray->dir.y = target->y - aray->pos.y;
	aray->dir.z = target->z - aray->pos.z;
	vector_normalize(&aray->dir);
	aray->t = -1;
}

static int	check_spot(t_ray *r, t_v3d *ai, t_spot *s, t_obj *o, int c) 
{
	t_spot	*tmp_s;
	t_obj	*tmp_o;
	t_v3d	v;
	int		smash;
	int		c_def;
	double	dist_s;

	tmp_s = s;
	smash = 0;
	c_def = c;
	r->check_spot = 1;
	set_to(&r->pos, ai);
	while (tmp_s)
	{
		set_to(&v, &tmp_s->pos);
		//aray->dir.x = v->x - ai.x;
	//	aray->dir.y = v->y - ai.y;
	//	aray->dir.z = v->z - ai.z;
		set_to(&r->dir, (vector_sub(&v, &r->pos)));
		vector_normalize(&r->dir);
		tmp_o = o;
		smash = 0;
		while (tmp_o && !smash)
		{
			dist_s = vector_dist(*ai, tmp_s->pos);
			if ((smash = tmp_o->smash(tmp_o, r)) && (r->t - 0.111111 < dist_s) && (r->t - 0.111111 > 0))
				c_def = (int)(c * 0.5);
			tmp_o = tmp_o->next;
		}
		tmp_s = tmp_s->next;
	}
	return (c_def);
}

static void	smash_up(t_all *all)
{
	all->acur = all->aobj;
	all->aray->check_spot = 0;
	while (all->acur)
	{
		if ((all->acur->smash(all->acur, all->aray)))
			if ((!(all->dist > -1.00000000) && !(all->dist < -1.00000000)
						&& all->aray->t > 0) || (0 < all->aray->t
							&& all->aray->t < all->dist))
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
			all->dist = -1.00000000;
			define_rayon(&target, all->aray, all->acam);
			smash_up(all);
			if (all->dist > -1.00000000 || all->dist < -1.00000000)
			{
				all->color = check_spot(all->aray, all->ai, all->aspot,
						all->aobj, all->color); 
				color_one_pixel_secure(all->color, all->aimg, xy[0], xy[1]);
			}
			vector_translate(&target, all->acam->dir_x, COEFW);
		}
		vector_translate(&target, all->acam->dir_x, -COEFW * (double)WINW);
		vector_translate(&target, all->acam->dir_z, -COEFH);
	}
}
