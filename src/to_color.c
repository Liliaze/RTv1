/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:03:20 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/07 18:28:04 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_rgb	*rgb_scale_max(t_rgb *src)
{
	src->r = (src->r > 255 ? 255 : src->r);
	src->g = (src->g > 255 ? 255 : src->g);
	src->b = (src->b > 255 ? 255 : src->b);
	return (src);
}

void	add_rgb(t_rgb *s1, t_rgb *s2)
{
	s1->r += s2->r;
	s1->g += s2->g;
	s1->b += s2->b;
}

t_rgb	*rgb_coef(t_rgb *src, double coef)
{
	src->r = (int)(src->r * coef);
	src->g = (int)(src->g * coef);
	src->b = (int)(src->b * coef);
	return (src);
}

int		rgb_to_int(t_rgb *src)
{
	src = rgb_scale_max(src);
	return (((int)((src->r << 16) + (src->g << 8) + src->b)));
}

t_rgb	*rgb_set_to(t_rgb *dest, t_rgb *src)
{
	dest->r = src->r;
	dest->g = src->g;
	dest->b = src->b;
	return (dest);
}
