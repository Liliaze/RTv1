/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:16:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/09 11:09:48 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

static int	smash_up(t_all *all)
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
				all->dist = all->aray->t;
				set_to(all->ai, &all->aray->i);
				all->ac = rgb_set_to(all->ac, &acur->c);
			}
		acur = acur->next;
	}
	return (1);
}

void		ray_tracing(t_all *all)
{
	int		xy[2];
	int		color;
	t_v3d	target;

	if (!(color = 0) && all->nb_o == 0)
		return ;
	define_target(all->acam, &target);
	xy[1] = -1;
	while (++xy[1] < WINH)
	{
		xy[0] = -1;
		while (++xy[0] < WINW)
		{
			all->dist = -1.00000000;
			define_rayon(&target, all->aray, all->acam);
			if (smash_up(all) && all->dist > -1.00000000)
			{
				color = check_spot(all, color);
				color_one_px_sec(color, all->aimg, xy[0], xy[1]);
			}
			vector_translate(&target, all->acam->dir_x, COEFW);
		}
		vector_translate(&target, all->acam->dir_x, -COEFW * (double)WINW);
		vector_translate(&target, all->acam->dir_z, -COEFH);
	}
}
