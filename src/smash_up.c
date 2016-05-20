/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:32:02 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/20 19:09:31 by dboudy           ###   ########.fr       */
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

	set_to(&v, &(aray->origin));
	vector_sub(&v, &(sphere->origin));
	tmp[0] = vector_dot(&(aray->dir), &(aray->dir));
	tmp[1] = 2 * (vector_dot(&(aray->dir), &v));
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
	double	tmp[3];
	double	res[3];
	t_v3d	v;

	set_to(&v, &(aray->origin));
	vector_sub(&v, &(cone->origin));
	tmp[0] = vector_dot(&(aray->dir), &(aray->dir));
	tmp[1] = 2 * (vector_dot(&(aray->dir), &v));
	tmp[2] = (vector_dot(&v, &v) - (cone->size * cone->size));
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

int		smash_cylindre(t_obj *cyl, t_ray *aray)
{
	double	tmp[3];
	double	res[3];
	t_v3d	v;

	set_to(&v, &(aray->origin));
	vector_sub2d(&v, &(cyl->origin));
	tmp[0] = vector_dot2d(&(aray->dir), &(aray->dir));
	tmp[1] = 2 * (vector_dot2d(&(aray->dir), &v));
	tmp[2] = (vector_dot2d(&v, &v) - (cyl->size * cyl->size));
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
