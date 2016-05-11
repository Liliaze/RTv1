/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cercle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:58:26 by dboudy            #+#    #+#             */
/*   Updated: 2016/04/26 11:07:11 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

/*
void	init_cercle(t_shape *cercle)
{
	cercle->
}
*/
void	draw_cercle(t_image *img, t_shape *cercle)
{
	double	angle;
	double	incrementation;
	double	pi_double;
	int		xtmp;
	int		ytmp;

	angle = 0;
	pi_double = 6.28318530718;
	if (cercle->rayon1_x > cercle->rayon2_y)
		incrementation = pi_double / (8 * cercle->rayon1_x);
	else
		incrementation = pi_double / (8 * cercle->rayon2_y);
	while (angle < pi_double)
	{
		xtmp = cercle->centre_x + (int)(round(cercle->rayon1_x * cos(angle)));
		ytmp = cercle->centre_y + (int)(round(cercle->rayon2_y * sin(angle)));
		color_one_pixel_secure(cercle->color_shape, img, xtmp, ytmp);
		angle += incrementation;
	}
}
