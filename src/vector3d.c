/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:08:47 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/09 11:37:16 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_v3d	*vector_sub(t_v3d *a, t_v3d *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
	return (a);
}

void	vector_translate(t_v3d *a, t_v3d b, double coef)
{
	a->x += b.x * coef;
	a->y += b.y * coef;
	a->z += b.z * coef;
}

t_v3d	*vector_add(t_v3d *v1, t_v3d *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
	return (v1);
}

double	vector_dot(t_v3d *a, t_v3d *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

double	vector_dist(t_v3d a, t_v3d b)
{
	double	r;

	r = pow(a.x - b.x, 2.0);
	return (sqrt(r + pow(a.y - b.y, 2.0) + pow(a.z - b.z, 2.0)));
}
