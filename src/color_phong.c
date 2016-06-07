/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_phong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 18:31:58 by edelangh          #+#    #+#             */
/*   Updated: 2015/03/22 14:23:55 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	color_reflexion(t_env *e, t_obj *obj, t_vect *n, int a)
{
	t_vect	r;
	t_vect	tmp2;
	double	color[5];
	int		i;
	t_obj	*res;

	scalar_multiply(set_to(&r, n), dot_product(n, &(e->save_dir)) * 2);
	subtract(set_to(&tmp2, &(e->save_dir)), &r);
	normalize(set_to(&r, &tmp2));
	color[4] = obj->reflexion;
	i = -1;
	color[3] = MAX_DIST;
	res = NULL;
	while (e->tab_obj[++i])
		if (i != obj->id &&
				e->tab_obj[i]->hit(e->tab_obj[i], e->r_dir, &r, &(color[3])))
			res = e->tab_obj[i];
	ft_memcpy(color, &(e->r), sizeof(double) * 3);
	e->r_pos = e->r_dir;
	e->r_dir = &r;
	if (color[3] != MAX_DIST)
		color_phong(e, res, color[3], a - 1);
	e->r = color[0] * (1 - color[4]) + (e->r * color[4]);
	e->v = color[1] * (1 - color[4]) + (e->v * color[4]);
	e->b = color[2] * (1 - color[4]) + (e->b * color[4]);
}

int		color_specular(t_env *e, t_vect *n, t_spot *spot)
{
	t_vect	inv_spot;
	double	tmp;

	set_to(&inv_spot, &(spot->dir));
	scalar_multiply(&inv_spot, -1);
	tmp = -dot_product(&inv_spot, n);
	if (tmp > 0)
	{
		tmp = pow(tmp, 64) * spot->i * 0.4;
		e->r += tmp;
		e->v += tmp;
		e->b += tmp;
	}
	return (0);
}

int		color_diffuse(t_env *e, t_vect *n, t_spot *spot, t_obj *obj)
{
	double	tmp;

	tmp = dot_product(n, &(spot->dir));
	if (tmp > 0)
	{
		e->r += ((double)((obj->color >> 16) & 0xFF) / 0xFF) * spot->r * tmp;
		e->v += ((double)((obj->color >> 8) & 0xFF) / 0xFF) * spot->v * tmp;
		e->b += ((double)((obj->color >> 0) & 0xFF) / 0xFF) * spot->b * tmp;
	}
	return (0);
}

int		color_phong2(t_env *e, t_obj *obj, t_vect *n, int a)
{
	int		i;
	t_vect	intersection;

	i = -1;
	while (++i < e->n_spot)
	{
		add(set_to(&intersection, e->r_pos), e->r_dir);
		if (!try_collision(e, &intersection, obj->id, &(e->spots[i])))
		{
			color_diffuse(e, n, &(e->spots[i]), obj);
			color_specular(e, n, &(e->spots[i]));
		}
	}
	if (a && obj->reflexion)
	{
		add(e->r_dir, &(e->pos));
		color_reflexion(e, obj, n, a);
	}
	e->r = (e->r > 1.0 ? 1.0 : e->r);
	e->v = (e->v > 1.0 ? 1.0 : e->v);
	e->b = (e->b > 1.0 ? 1.0 : e->b);
	return (0);
}

int		color_phong(t_env *e, t_obj *obj, double dist, int a)
{
	t_vect	n;
	t_vect	*ray;
	t_vect	*r_pos;

	ray = e->r_dir;
	set_to(&(e->save_dir), ray);
	r_pos = e->r_pos;
	e->r = ((double)((obj->color >> 16) & 0xFF) / 0xFF) * 0.1;
	e->v = ((double)((obj->color >> 8) & 0xFF) / 0xFF) * 0.1;
	e->b = ((double)((obj->color >> 0) & 0xFF) / 0xFF) * 0.1;
	scalar_multiply(ray, dist);
	init_spots(e, r_pos, ray);
	obj->norm(&(e->pos), obj, ray, &n);
	return (color_phong2(e, obj, &n, a));
}
