/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:03:20 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/08 16:53:11 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	rgb_to_int_coef(t_rgb *s1, double coef)
{
	int		rgb[3];

	rgb[0] = s1->r;
	rgb[1] = s1->g;
	rgb[2] = s1->b;
	rgb[0] = (rgb[0] > 255 ? 255 : abs(rgb[0]));
	rgb[1] = (rgb[1] > 255 ? 255 : abs(rgb[1]));
	rgb[2] = (rgb[2] > 255 ? 255 : abs(rgb[2]));
	rgb[0] = (int)(rgb[0] * coef);
	rgb[1] = (int)(rgb[1] * coef);
	rgb[2] = (int)(rgb[2] * coef);
	rgb[0] = (rgb[0] > 255 ? 255 : abs(rgb[0]));
	rgb[1] = (rgb[1] > 255 ? 255 : abs(rgb[1]));
	rgb[2] = (rgb[2] > 255 ? 255 : abs(rgb[2]));
	return (((int)((rgb[0] << 16) + (rgb[1] << 8) + rgb[2])));
}

t_rgb	*rgb_coef(t_rgb *src, double coef)
{
	src->r = (int)(src->r * coef);
	src->g = (int)(src->g * coef);
	src->b = (int)(src->b * coef);
	return (src);
}

int		add_int_rgb(int	c, int c2)
{
	int		rgb[6];
	
	rgb[0] = (int)(c >> 16 & 0xFF);
	rgb[1] = (int)(c >> 8 & 0xFF);
	rgb[2] = (int)(c >> 0 & 0xFF);
	rgb[3] = (int)(c2 >> 16 & 0xFF);
	rgb[4] = (int)(c2 >> 8 & 0xFF);
	rgb[5] = (int)(c2 >> 0 & 0xFF);
	rgb[0] = (rgb[0] > 255 ? 255 : abs(rgb[0]));
	rgb[1] = (rgb[1] > 255 ? 255 : abs(rgb[1]));
	rgb[2] = (rgb[2] > 255 ? 255 : abs(rgb[2]));
	rgb[3] = (rgb[3] > 255 ? 255 : abs(rgb[3]));
	rgb[4] = (rgb[4] > 255 ? 255 : abs(rgb[4]));
	rgb[5] = (rgb[5] > 255 ? 255 : abs(rgb[5]));
	rgb[0] = rgb[0] + rgb[3];
	rgb[1] = rgb[1] + rgb[4];
	rgb[2] = rgb[2] + rgb[5];
	return (((int)((rgb[0] << 16) + (rgb[1] << 8) + rgb[2])));
}

int		rgb_to_int(t_rgb *src)
{
	src->r = (src->r > 255 ? 255 : abs(src->r));
	src->g = (src->g > 255 ? 255 : abs(src->g));
	src->b = (src->b > 255 ? 255 : abs(src->b));
	return (((int)((src->r << 16) + (src->g << 8) + src->b)));
}

t_rgb	*rgb_set_to(t_rgb *dest, t_rgb *src)
{
	dest->r = src->r;
	dest->g = src->g;
	dest->b = src->b;
	dest->r = (dest->r > 255 ? 255 : abs(dest->r));
	dest->g = (dest->g > 255 ? 255 : abs(dest->g));
	dest->b = (dest->b > 255 ? 255 : abs(dest->b));
	return (dest);
}
