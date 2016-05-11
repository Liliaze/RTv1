/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:23:38 by dboudy            #+#    #+#             */
/*   Updated: 2016/04/25 11:47:29 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	color_pixel(t_image *img, int color, int x, int y)
{
	int *tmp;
	int pixel;

	tmp = (int*)(void*)img->image;
	pixel = x * img->bpp + y * img->size_line;
	if (x >= 0 && x < img->size_line && y >= 0 &&
			y < (img->last_pixel / img->size_line))
		tmp[pixel] = color;
}

inline static void	bres_dx_sup(t_bres *abres, t_image *img)
{
	int	i;
	int e;
	int inc1;
	int inc2;

	i = 0;
	color_pixel(img, abres->color_bres, abres->x_origin, abres->y_origin);
	e = 2 * abres->dy - abres->dx;
	inc1 = 2 * (abres->dy - abres->dx);
	inc2 = 2 * abres->dy;
	while (i < abres->dx)
	{
		if (e >= 0)
		{
			abres->y_origin += abres->incy;
			e += inc1;
		}
		else
			e += inc2;
		abres->x_origin += abres->incx;
		color_pixel(img, abres->color_bres, abres->x_origin, abres->y_origin);
		i++;
	}
}

inline static void	bres_else(t_bres *abres, t_image *img)
{
	int	i;
	int	e;
	int inc1;
	int inc2;

	i = 0;
	color_pixel(img, abres->color_bres, abres->x_origin, abres->y_origin);
	e = 2 * abres->dx - abres->dy;
	inc1 = 2 * (abres->dx - abres->dy);
	inc2 = 2 * abres->dx;
	while (i < abres->dy)
	{
		if (e >= 0)
		{
			abres->x_origin += abres->incx;
			e += inc1;
		}
		else
			e += inc2;
		abres->y_origin += abres->incy;
		color_pixel(img, abres->color_bres, abres->x_origin, abres->y_origin);
		i++;
	}
}

int					bres(t_bres *abres, t_image *img)
{
	abres->dx = abres->x_dest - abres->x_origin;
	abres->dy = abres->y_dest - abres->y_origin;
	if (abres->dx < 0)
		abres->dx = -abres->dx;
	if (abres->dy < 0)
		abres->dy = -abres->dy;
	abres->incx = 1;
	if (abres->x_dest < abres->x_origin)
		abres->incx = -1;
	abres->incy = 1;
	if (abres->y_dest < abres->y_origin)
		abres->incy = -1;
	if (abres->dx > abres->dy)
		bres_dx_sup(abres, img);
	else
		bres_else(abres, img);
	return (0);
}
