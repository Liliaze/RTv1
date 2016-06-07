/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:32:02 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/07 14:28:27 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	norm_plan(t_obj *plan, t_ray *aray, t_v3d *n)
{
	set_to(n, &plan->dir);
	vector_normalize(n);
	if (vector_dot(n, &aray->dir) < 0)
		scalar_multiply(n, -1);
}

void	norm_sphere(t_obj *sphere, t_ray *aray, t_v3d *n)
{
	set_to(n, &aray->dir);
	vector_add(n, &aray->pos);
	vector_sub(n, &sphere->pos);
	scalar_multiply(n, -1);
	vector_normalize(n);
}

void	norm_cone(t_obj *cone, t_ray *aray, t_v3d *n)
{
	set_to(n, &cone->dir);
	vector_normalize(n);
	if (vector_dot(n, &aray->dir) < 0)
		scalar_multiply(n, -1);
}

void	norm_cyl(t_obj *cyl, t_ray *aray, t_v3d *n)
{
	set_to(n, &cyl->dir);
	vector_normalize(n);
	if (vector_dot(n, &aray->dir) < 0)
		scalar_multiply(n, -1);
}
