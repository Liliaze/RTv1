/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:32:02 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/25 16:58:30 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include "libft.h"

int		smash_plan(t_obj *plan, t_ray *aray)
{
	t_v3d	v;

	set_to(&v, &(aray->origin));
	vector_sub(&v, &(plan->origin));
	aray->t = -(vector_dot(&v, &(plan->dir))
			/ vector_dot(&(plan->dir), &(aray->dir)));
	if (aray->t > 0)
		return (1);
	return (0);
}

int		smash_sphere(t_obj *sphere, t_ray *aray)
{
	double	tmp[3];
	double	res[3];
	t_v3d	v;

	set_to(&v, &aray->origin);
	vector_sub(&v, &sphere->origin);
	tmp[0] = vector_dot(&aray->dir, &aray->dir);
	tmp[1] = 2 * (vector_dot(&aray->dir, &v));
	tmp[2] = (vector_dot(&v, &v) - (sphere->size * sphere->size));
	res[0] = (tmp[1] * tmp[1]) - (4 * tmp[0] * tmp[2]);
	if (res[0] >= 0)
	{
		res[1] = (-tmp[1] + sqrt(res[0])) / (2 * tmp[0]);
		res[2] = (-tmp[1] - sqrt(res[0])) / (2 * tmp[0]);
		if (res[1] < res[2])
			aray->t = res[1];
		else
			aray->t = res[2];
		return (1);
	}
	return (0);
}

int		smash_cone(t_obj *cone, t_ray *aray)
{
	t_v3d	v;
	t_v3d	y;
	double		abc[3];
	double		res[3];

	set_to(&v, &aray->origin);
	set_to(&y, &cone->dir);
	vector_normalize(&y);
	vector_sub(&v, &cone->origin);
	abc[0] = vector_dot(&aray->dir, &aray->dir) - ((1 + cone->size * cone->size)
			* vector_dot(&aray->dir, &y) * vector_dot(&aray->dir, &y));
	abc[1] = 2 * (vector_dot(&aray->dir, &v) - ((1 + cone->size * cone->size)
				* vector_dot(&aray->dir, &y) * vector_dot(&v, &y)));
	abc[2] = vector_dot(&v, &v) - ((1 + cone->size * cone->size)
			* vector_dot(&v, &y) * vector_dot(&v, &y));
	res[0] = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (res[0] >= 0)
	{
		res[1] = (-abc[1] + sqrtf(res[0])) / (2 * abc[0]);
		res[2] = (-abc[1] - sqrtf(res[0])) / (2 * abc[0]);
		if (res[1] < res[2])
			aray->t = res[1];
		else
			aray->t = res[2];
		return (1);
		//cone->i = vect(r.origin.x + &ray->dir.x * t[2], r.origin.y + &ray->dir.y * t[2], 0);
		//cone->i.z = r.origin.z + &ray->dir.z * t[2];
	}
	return (0);
}

int		smash_cylindre(t_obj *cyl, t_ray *aray)
{
	t_v3d		v;
	double		tmp[4];
	double		abc[3];
	double		res[3];

	set_to(&v, &aray->origin);
	vector_sub(&v, &cyl->origin);
	tmp[0] = vector_dot(&cyl->dir, &cyl->dir);
	tmp[1] = vector_dot(&cyl->dir, &aray->dir);
	tmp[2] = vector_dot(&v, &v);
	tmp[3] = vector_dot(&cyl->dir, &v);
	abc[0] = vector_dot(&aray->dir, &aray->dir) - ((tmp[1] * tmp[1]) / tmp[0]);
	abc[1] = 2 * vector_dot(&aray->dir, &v) - (2 * tmp[1] * tmp[3] / tmp[0]);
	abc[2] = tmp[2] - (cyl->size * cyl->size) - ((tmp[3] * tmp[3]) / tmp[0]);
	res[0] = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (res[0] >= 0)
	{
		res[1] = (-abc[1] + sqrtf(res[0])) / (2 * abc[0]);
		res[2] = (-abc[1] - sqrtf(res[0])) / (2 * abc[0]);
		if (res[1] < res[2])
			aray->t = res[1];
		else
			aray->t = res[2];
		return (1);
	}
	return (0);
}

void	smash_up(t_all *all)
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
		}
		all->acur = all->acur->next;
	}
}
