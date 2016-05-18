/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:32:02 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/18 19:06:32 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include "libft.h"

int		smash_plan(t_obj *plan, t_ray *aray)
{
	t_v3d	*v;

	v = vector_sub(&(aray->origin), &(plan->origin));
	aray->t = -(vector_dot(v, &(plan->dir))
			/ vector_dot(&(plan->dir), &(aray->dir)));
	free(v);
	if (aray->t > 0)
		return (1);
	return (0);
}

int		smash_sphere(t_obj *sphere, t_ray *aray)
{
	double	tmp[3];
	double	res[3];
	t_v3d	*v;

	v = vector_sub(&(aray->origin), &(sphere->origin));
	tmp[0] = vector_dot(&(aray->dir), &(aray->dir));
	tmp[1] = 2 * (vector_dot(&(aray->dir), v));
	tmp[2] = (vector_dot(v, v) - (sphere->size * sphere->size));
	res[0] = tmp[1] * tmp[1] - 4 * tmp[0] * tmp[2];
	if (res[0] >= 0.000)
	{
		res[1] = (-tmp[1] + sqrt(res[0])) / (2 * tmp[0]);
		res[2] = (-tmp[1] - sqrt(res[0])) / (2 * tmp[0]);
		if (res[1] < res[2])
			aray->t = res[1];
		else
			aray->t = res[2];
		free(v);
		return (1);
	}
	free(v);
	return (0);
}

int		smash_check(t_all *all)
{
	t_obj	*tmp;

	tmp = all->aobj;
	while (tmp)
	{
		tmp->smash(tmp, all->aray);
		if (((all->dist > -1.0000 || all->dist < -1.0000) && all->aray->t > 0)
				|| (0 < all->aray->t && all->aray->t < all->dist))
		{
			all->dist = all->aray->t;
			all->color = tmp->color;
		}
		tmp = tmp->next;
	}
	return (1);
}
