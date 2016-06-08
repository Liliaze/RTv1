/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:08:47 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/08 16:32:22 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_v3d	*set_to(t_v3d *a, t_v3d *b)
{
	a->x = b->x;
	a->y = b->y;
	a->z = b->z;
	return (a);
}

void	vector_normalize(t_v3d *v)
{
	double	tmp;

	tmp = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x = v->x / tmp;
	v->y = v->y / tmp;
	v->z = v->z / tmp;
}

t_v3d	*vector_sub(t_v3d *a, t_v3d *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
	return (a);
}
/*
t_v3d	*vector_subtmp(t_v3d *a, t_v3d *b)
{
	t_v3d	*tmp;

	tmp = (t_v3d *)ft_memalloc(sizeof(tmp));
	tmp->x = a->x - b->x;
	tmp->y = a->y - b->y;
	tmp->z = a->z - b->z;
	return (tmp);
}*/

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

double		vector_dot(t_v3d *a, t_v3d *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

double       vector_dist(t_v3d a, t_v3d b)
{
	double    r;

	r = pow(a.x - b.x, 2.0);
	return (sqrt(r + pow(a.y - b.y, 2.0) + pow(a.z - b.z, 2.0)));
}
