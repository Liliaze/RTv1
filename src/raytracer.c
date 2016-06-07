/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:16:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/07 18:28:06 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <math.h>

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
/*
static void		color_specular(t_v3d *an, t_rgb *c, t_v3d *dir_spot, short nb_spot)
{
	t_v3d	inv_spot;
	double	tmp;

	set_to(&inv_spot, dir_spot);
	scalar_multiply(&inv_spot, -1);
	tmp = -vector_dot(&inv_spot, an);
	if (tmp > 0)
	{
		tmp = pow(tmp, 64) * nb_spot * 0.4;
		c->r += tmp;
		c->g += tmp;
		c->b += tmp;
	}
}

static void		color_diffuse(t_v3d *an, t_rgb *c, t_spot *spot)
{
	double	tmp;

	tmp = vector_dot(an, &(spot->dir));
	if (tmp > 0)
	{
		c->r += (int)(spot->c.r * tmp);
		c->g += (int)(spot->c.g * tmp);
		c->b += (int)(spot->c.b * tmp);
	}
}
*/
static void	check_spot(t_all *all) 
{
	t_spot	*tmp_s;
	t_obj	*tmp_o;
	t_v3d	v;
	int		smash;
	double	dist_s;

	tmp_s = all->aspot;
	dist_s = 0.0;
	all->aray->check_spot = 1;
	set_to(&all->aray->pos, all->ai);
	while (tmp_s)
	{
		set_to(&v, &tmp_s->pos);
		set_to(&all->aray->dir, (vector_sub(&v, &all->aray->pos)));
		vector_normalize(&all->aray->dir);
		tmp_o = all->aobj;
		smash = 0;
		dist_s = vector_dist(*all->ai, tmp_s->pos);
		while (tmp_o && !smash)
		{
			smash = tmp_o->smash(tmp_o, all->aray);
			if (smash && !(all->aray->t - 0.001 < dist_s && all->aray->t > 0.0000001))
				smash = 0;
			tmp_o = tmp_o->next;
		}
		if (!smash)
		{
			//add_rgb(all->ac, all->ac, rgb_coef(&tmp_s->c, 0.1));
			all->ac = rgb_coef(all->ac, 1 / (fabs(dist_s) * 0.005));
			//add_rgb(all->ac, rgb_coef(&tmp_s->c, 0.1));
			//add_rgb(all->ac, all->ac, rgb_coef(&tmp_s->c, (dist_s * 0.05)));
		}
		tmp_s = tmp_s->next;
	}
}

static void	smash_up(t_all *all)
{
	t_obj	*acur;

	acur = all->aobj;
	all->aray->check_spot = 0;
	while (acur)
	{
		if ((acur->smash(acur, all->aray)))
			if ((!(all->dist > -1.00000000) && !(all->dist < -1.00000000)
						&& all->aray->t > 0) || (0 < all->aray->t
							&& all->aray->t < all->dist))
			{
				acur->norm(acur, all->aray, all->an);
				all->dist = all->aray->t;
				all->ac = rgb_coef(rgb_set_to(all->ac, &acur->c), 0.1);
				set_to(all->ai, &all->aray->i);
			}
		acur = acur->next;
	}
}

void	ray_tracing(t_all	*all)
{
	int		xy[2];
	t_v3d	target;

	if (all->nb_obj == 0)
		return;
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
				if (all->nb_spot != 0)
					check_spot(all); 
				color_one_px_sec(rgb_to_int(all->ac), all->aimg, xy[0], xy[1]);
			}
			vector_translate(&target, all->acam->dir_x, COEFW);
		}
		vector_translate(&target, all->acam->dir_x, -COEFW * (double)WINW);
		vector_translate(&target, all->acam->dir_z, -COEFH);
	}
}
