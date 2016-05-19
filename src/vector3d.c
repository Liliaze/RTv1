/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:08:47 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/19 16:26:41 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <math.h>

void	vector_normalize(t_v3d *v)
{
	double	tmp;
	
	tmp = 1 / sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x = v->x * tmp;
	v->y = v->y * tmp;
	v->z = v->z * tmp;
}

t_v3d	*vector_sub(t_v3d *a, t_v3d *b)
{
	t_v3d	*tmp;
	
	tmp = (t_v3d *)ft_memalloc(sizeof(tmp));
	tmp->x = a->x - b->x;
	tmp->y = a->y - b->y;
	tmp->z = a->z - b->z;
	return (tmp);
}

void	vector_mult(t_v3d *a, t_v3d *b)
{
	a->x *= b->x;
	a->y *= b->y;
	a->z *= b->z;
}

void	vector_translate(t_v3d *a, t_v3d b, double coef)
{
	a->x += b.x * coef;
	a->y += b.y * coef;
	a->z += b.z * coef;
}

double		vector_dot(t_v3d *a, t_v3d *b)
{
	double	dot;

	dot = a->x * b->x + a->y * b->y + a->z * b->z;
	return (dot);
}
	
t_v3d		*vector_copy(t_v3d *v)
{
	t_v3d	*new;

	new = (t_v3d *)ft_memalloc(sizeof(t_v3d));
	new->x = v->x;
	new->y = v->y;
	new->z = v->z;
	return (new);
}
	
