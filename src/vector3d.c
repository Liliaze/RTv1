/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:08:47 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/27 19:16:58 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <math.h>
/*
double	to_rad(double r)
{
	return (r * M_PI / 180.0);
}
double	saturate(double n)
{
	return (clamp(n, 0.0, 1.0));
}

t_v3d	*saturate_vec(t_v3d *n)
{
	return (clamp_vec(n, 0.0, 1.0));
}

double	length_vec(t_v3d *z)
{
	return (sqrt(z->x * z->x + z->y * z->y + z->z * z->z));
}
*/
void	printv(t_v3d v)
{
	printf("x-%f, y-%f, z-%f\n", v.x, v.y, v.z);
}

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
/*
t_v3d	*vector_sub2d(t_v3d *a, t_v3d *b)
{
	a->x -= b->x;
	a->y -= b->y;
	return (a);
}
*/
t_v3d	*vector_sub(t_v3d *a, t_v3d *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
	return (a);
}
/*
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
*/
void	vector_translate(t_v3d *a, t_v3d b, double coef)
{
	a->x += b.x * coef;
	a->y += b.y * coef;
	a->z += b.z * coef;
}
/*
t_v3d	*add(t_v3d *v1, t_v3d *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
	return (v1);
}

double		vector_dot2dxz(t_v3d *a, t_v3d *b)
{
	return (a->x * b->x + a->z * b->z);
}

double		vector_dotxz_subycoef(t_v3d *a, t_v3d *b, double ecart)
{
	return (a->x * b->x + a->z * b->z - a->y * b->y * ecart);
}

double		vector_dot_cone(t_v3d *a, t_v3d *b)
{
	return (a->x * b->x - a->y * b->y + a->z * b->z);
}
*/
double		vector_dot(t_v3d *a, t_v3d *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
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
/*
t_v3d	*clamp_vec(t_v3d *v1, double min, double max)
{
	v1->x = clamp(v1->x, min, max);
	v1->y = clamp(v1->y, min, max);
	v1->z = clamp(v1->z, min, max);
	return (v1);
}

double	clamp(double n, double min2, double max2)
{
	if (n > max2)
	{
		if (min2 > max2)
			return (min2);
		else
			return (max2);
	}
	else
	{
		if (min2 > n)
			return (min2);
		else
			return (n);
	}
}

t_v3d	*turn_orthogonal(t_v3d *v1)
{
	double inverse;
	double old_x;

	inverse = 1.0 / sqrt(v1->x * v1->x + v1->z * v1->z);
	old_x = v1->x;
	v1->x = -inverse * v1->z;
	v1->z = inverse * old_x;
	return (v1);
}

t_v3d	*cross_product(t_v3d *v1, t_v3d *v2)
{
	double	old_x;
	double	old_y;

	old_x = v1->x;
	old_y = v1->y;
	v1->x = v2->y * v1->z - v2->z * old_y;
	v1->y = v2->z * old_x - v2->x * v1->z;
	v1->z = v2->x * old_y - v2->y * old_x;
	return (v1);
}

t_v3d	*scalar_multiply(t_v3d *a, double amount)
{
	a->x *= amount;
	a->y *= amount;
	a->z *= amount;
	return (a);
}*/
