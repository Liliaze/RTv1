/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:08:47 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/12 17:40:51 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <math.h>

void	vector_normalize(t_vec3d *v)
{
	double	tmp;
	
	tmp = 1 / sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x = v->x * tmp;
	v->y = v->y * tmp;
	v->z = v->z * tmp;
}

void	vector_sub(t_vec3d *a, t_vec3d *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
}

void	vector_mult(t_vec3d *a, t_vec3d *b)
{
	a->x *= b->x;
	a->y *= b->y;
	a->z *= b->z;
}

void	vector_translate(t_vec3d *a, t_vec3d *b, double coef)
{
	a->x += b->x * coef;
	a->y += b->y * coef;
	a->z += b->z * coef;
}

double		vector_dot(t_vec3d *a, t_vec3d *b)
{
	double	dot;

	dot = a->x * b->x + a->y * b->y + a->z * b->z;
	return (dot);
}
	
t_vec3d		*vector_copy(t_vec3d *v)
{
	t_vec3d	*new;

	new = (t_vec3d *)ft_memalloc(sizeof(t_vec3d));
	new->x = v->x;
	new->y = v->y;
	new->z = v->z;
	return (new);
}
	