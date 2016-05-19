/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:32:02 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/19 16:07:03 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include "libft.h"

int		smash_plan(t_obj *plan, t_ray *aray)
{
	double	x;
	double	y;
	double	z;

	x = aray->origin.x - plan->origin.x;
	y = aray->origin.y - plan->origin.y;
	z = aray->origin.z - plan->origin.z;
	aray->t = -((plan->dir.x * x + plan->dir.y * y + plan->dir.z * z)
			/ (plan->dir.x * aray->dir.x + plan->dir.y *
				aray->dir.y + plan->dir.z * aray->dir.z));
	if (aray->t > 0)
		return (1);
	else
		return (0);
	/*
	   t_v3d	*v;

	   v = vector_sub(&(aray->origin), &(plan->origin));
	   aray->t = -(vector_dot(v, &(plan->dir))
	   / vector_dot(&(plan->dir), &(aray->dir)));
	   printf("aray->t plan = %f\n", aray->t);
	   free(&v);
	   if (aray->t > 0)
	   return (1);
	   return (0);*/
}

int		smash_sphere(t_obj *sphere, t_ray *aray)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(aray->dir.x, 2) + pow(aray->dir.y, 2) + pow(aray->dir.z, 2);
	b = 2 * (aray->dir.x * (aray->origin.x - sphere->origin.x) +
			aray->dir.y * (aray->origin.y - sphere->origin.y) +
			aray->dir.z * (aray->origin.z - sphere->origin.z));
	c = (pow(aray->origin.x - sphere->origin.x, 2) + pow(aray->origin.y - sphere->origin.y, 2) +
			pow(aray->origin.z - sphere->origin.z, 2)) - pow(sphere->size, 2);
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		aray->t =
			((-b + sqrt(det)) / (2 * a) < (-b - sqrt(det)) / (2 * a)) ?
			(-b + sqrt(det)) / (2 * a) : (-b - sqrt(det)) / (2 * a);
		return (1);
	}
	else
		return (0);
	/*
	   double	tmp[3];
	   double	res[3];
	   t_v3d	*v;

	   v = vector_sub(&(aray->origin), &(sphere->origin));
	   tmp[0] = vector_dot(&(aray->dir), &(aray->dir));
	   tmp[1] = 2 * (vector_dot(&(aray->dir), v));
	   tmp[2] = (vector_dot(v, v) - (sphere->size * sphere->size));
	   res[0] = (tmp[1] * tmp[1]) - (4 * tmp[0] * tmp[2]);
	   if (res[0] >= 0)
	   {
	   res[1] = (-tmp[1] + sqrt(res[0])) / (2 * tmp[0]);
	   res[2] = (-tmp[1] - sqrt(res[0])) / (2 * tmp[0]);
	   if (res[1] < res[2])
	   aray->t = res[1];
	   else
	   aray->t = res[2];
	   free(v);
	   printf("aray->t sphere else = %f\n", aray->t);
	   return (1);
	   }
	   printf("aray->t sphere if = %f\n", aray->t);
	   free(v);
	   return (0);*/
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
