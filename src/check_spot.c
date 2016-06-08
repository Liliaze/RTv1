/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:16:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/08 17:33:22 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_hit(t_all *all, t_spot *s, int color)
{
	t_obj	*tmp_o;
	int		smash;
	double	t;

	smash = 0;
	tmp_o = all->aobj;
	t = vector_dist(*all->ai, s->pos);
	while (tmp_o && !smash)
	{
		smash = tmp_o->smash(tmp_o, all->aray);
		if (smash && !(all->aray->t - 0.001 < t && all->aray->t > 0.0000001))
			smash = 0;
		tmp_o = tmp_o->next;
	}
	if (!smash)
	{
		color = add_int_rgb(color, rgb_to_int_coef(all->ac, 0.18 / all->nb_s));
		color = add_int_rgb(color, rgb_to_int_coef(&s->c, 0.05 / all->nb_s));
		color = add_int_rgb(color, rgb_to_int_coef(&s->c,
					((1 / (t * 0.01)) / all->nb_s) * 0.018));
		color = add_int_rgb(color, rgb_to_int_coef(all->ac,
					((1 / (t * 0.01)) / all->nb_s) * 0.018));
	}
	return (color);
}

int			check_spot(t_all *all, int color) 
{
	t_spot	*tmp_s;
	t_v3d	v;
	t_rgb	tmp;

	color = rgb_to_int_coef(all->ac, 0.1);
	tmp = *rgb_set_to(&tmp, all->ac);
	if (all->aray->t > 10)
		tmp = *rgb_coef(&tmp, 1 / ((pow(all->dist, 3) * 0.001)));
	else if (all->aray->t > 0.01)
		tmp = *rgb_coef(&tmp, 1 / ((pow(all->dist + 11, 3) * 0.001)));
	color = add_int_rgb(color, rgb_to_int_coef(&tmp, 0.18));
	if (all->nb_s != 0)
	{
		tmp_s = all->aspot;
		all->aray->check_spot = 1;
		set_to(&all->aray->pos, all->ai);
		while (tmp_s)
		{
			set_to(&v, &tmp_s->pos);
			set_to(&all->aray->dir, (vector_sub(&v, &all->aray->pos)));
			vector_normalize(&all->aray->dir);
			color = check_hit(all, tmp_s, color);
			tmp_s = tmp_s->next;
		}
	}
	return (color);
}
