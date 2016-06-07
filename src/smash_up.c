/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:32:02 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/07 15:34:57 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include "libft.h"

static int	delta(double res[3], double abc[3], t_ray *aray, t_v3d *objpos)
{
	double	final_dist;

	(void)objpos;
	res[1] = (-abc[1] + sqrt(res[0])) / (2 * abc[0]);
	res[2] = (-abc[1] - sqrt(res[0])) / (2 * abc[0]);
	if (res[0] == 0.0)
		final_dist = res[1];
	else
	{
		final_dist = (res[1] < res[2] ? res[1] : res[2]);
		final_dist = (final_dist < 0 ? res[2] : final_dist);
	}
	if (final_dist < 0.0)
		return (0);
	aray->t = final_dist;
	/*
	   res[1] = (-abc[1] + sqrt(res[0])) / (2 * abc[0]);
	   res[2] = (-abc[1] - sqrt(res[0])) / (2 * abc[0]);
	   if (res[1] < res[2])
	   {
	   aray->t = res[1];
	   final_dist = res[1];
	   }
	   else
	   {
	   aray->t = res[2];
	   final_dist = res[2];
	   }*/
	if (!(aray->check_spot))
	{
		aray->i.x = aray->pos.x + aray->dir.x * final_dist;
		aray->i.y = aray->pos.y + aray->dir.y * final_dist;
		aray->i.z = aray->pos.z + aray->dir.z * final_dist;
	}
	return (1);
}

int		smash_plan(t_obj *plan, t_ray *aray)
{
	t_v3d	v;
	t_v3d	w;
	double tmp;

	set_to(&v, &(aray->pos));
	set_to(&w, &(plan->dir));
	vector_normalize(&w);
	vector_sub(&v, &(plan->pos));
	tmp = -(vector_dot(&v, &(plan->dir))
			/ vector_dot(&(plan->dir), &(aray->dir)));
	if (tmp <= 0.0)
		return (0);
	aray->t = tmp;
	if (!(aray->check_spot))
	{
		aray->i.x = aray->pos.x + aray->dir.x * tmp;
		aray->i.y = aray->pos.y + aray->dir.y * tmp;
		aray->i.z = aray->pos.z + aray->dir.z * tmp;
	}
	return (1);
}

int		smash_sphere(t_obj *sphere, t_ray *aray)
{
	double	abc[3];
	double	res[3];
	t_v3d	v;

	set_to(&v, &aray->pos);
	vector_sub(&v, &sphere->pos);
	abc[0] = vector_dot(&aray->dir, &aray->dir);
	abc[1] = 2 * (vector_dot(&aray->dir, &v));
	abc[2] = (vector_dot(&v, &v) - (sphere->size * sphere->size));
	res[0] = (abc[1] * abc[1]) - (4 * abc[0] * abc[2]);
	if (res[0] >= 0.0)
		return (delta(res, abc, aray, &sphere->pos));
	return (0);
}

int		smash_cone(t_obj *cone, t_ray *aray)
{
	t_v3d	v;
	t_v3d	y;
	double		abc[3];
	double		res[3];

	set_to(&v, &aray->pos);
	set_to(&y, &cone->dir);
	vector_normalize(&y);
	vector_sub(&v, &cone->pos);
	abc[0] = vector_dot(&aray->dir, &aray->dir) - ((1 + cone->size * cone->size)
			* vector_dot(&aray->dir, &y) * vector_dot(&aray->dir, &y));
	abc[1] = 2 * (vector_dot(&aray->dir, &v) - ((1 + cone->size * cone->size)
				* vector_dot(&aray->dir, &y) * vector_dot(&v, &y)));
	abc[2] = vector_dot(&v, &v) - ((1 + cone->size * cone->size)
			* vector_dot(&v, &y) * vector_dot(&v, &y));
	res[0] = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (res[0] >= 0.0)
		return (delta(res, abc, aray, &cone->pos));
	return (0);
}

int		smash_cyl(t_obj *cyl, t_ray *aray)
{
	t_v3d		v;
	double		tmp[4];
	double		abc[3];
	double		res[3];

	set_to(&v, &aray->pos);
	vector_sub(&v, &cyl->pos);
	tmp[0] = vector_dot(&cyl->dir, &cyl->dir);
	tmp[1] = vector_dot(&cyl->dir, &aray->dir);
	tmp[2] = vector_dot(&v, &v);
	tmp[3] = vector_dot(&cyl->dir, &v);
	abc[0] = vector_dot(&aray->dir, &aray->dir) - ((tmp[1] * tmp[1]) / tmp[0]);
	abc[1] = 2 * vector_dot(&aray->dir, &v) - (2 * tmp[1] * tmp[3] / tmp[0]);
	abc[2] = tmp[2] - (cyl->size * cyl->size) - ((tmp[3] * tmp[3]) / tmp[0]);
	res[0] = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (res[0] >= 0.0)
		return (delta(res, abc, aray, &cyl->pos));
	return (0);
}
