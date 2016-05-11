/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 13:33:26 by dboudy            #+#    #+#             */
/*   Updated: 2016/04/26 11:05:24 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	color_all_pixel(int	color, char *data, int last_pixel)
{
	int	*tmp;
	int i;

	i = 0;
	tmp = (int*)(void*)data;
	while (i < last_pixel)
	{
		tmp[i] = color;
		i++;
	}
}

void	color_one_pixel_secure(int color, t_image *img, int x, int y)
{
	int *tmp;
	int pixel;

	tmp = (int*)(void*)img->image;
	pixel = x + y * img->size_line;
	if (x >= 0 && x < img->size_line && y >= 0 && y < (img->last_pixel / img->size_line))
		tmp[pixel] = color;
}

static int		check_same_color(t_image *img, int x, int y, int color)
{
	int *tmp;
	int pixel;

	if (x >= 0 && x < img->size_line
			&& y >= 0 && y < (img->last_pixel / img->size_line))
	{
		tmp = (int*)(void*)img->image;
		pixel = x + y * img->size_line;
		if (tmp[pixel] != color)
			return (1);
	}
	return (0);
}
/*
int		degrade(int color)
{
	static int rappel = -1;
	int red;
	int green;
	int	blue;

	rappel++;
	if (rappel % 3)
	{
		red = (color >> 16) & 255;
		green = (color >> 8) & 255;
		blue = (color >> 0) & 255;
		if (red < 256)
			red = (int)(red + 1);
		if (green > 0)
			green = (int)(green - 1);
		if (blue > 0)
			blue = (int)(blue - 1);
		return ((red << 16) + (green << 8) + blue);
	}
	return (color);
}

void	fill_degrade_shape(t_image *img, int x, int y, int color_stop, int color_put)
{
	color_put = degrade(color_put);
	if (!check_same_color(img, x, y, color_stop))
		color_one_pixel_secure(color_put, img, x, y);
	if (!check_same_color(img, x + 1, y, color_stop))
		fill_degrade_shape(img, x + 1, y, color_stop, color_put);
	if (!check_same_color(img, x - 1, y, color_stop))
		fill_degrade_shape(img, x - 1, y, color_stop, color_put);
	if (!check_same_color(img, x, y + 1, color_stop))
		fill_degrade_shape(img, x, y + 1, color_stop, color_put);
	if (!check_same_color(img, x, y - 1, color_stop))
		fill_degrade_shape(img, x, y - 1, color_stop, color_put);
}
*/
void	fill_shape(t_image *img, int x, int y, int color)
{
	if (check_same_color(img, x, y, color))
		color_one_pixel_secure(color, img, x, y);
	if (check_same_color(img, x + 1, y, color))
		fill_shape(img, x + 1, y, color);
	if (check_same_color(img, x - 1, y, color))
		fill_shape(img, x - 1, y, color);
	if (check_same_color(img, x, y + 1, color))
		fill_shape(img, x, y + 1, color);
	if (check_same_color(img, x, y - 1, color))
		fill_shape(img, x, y - 1, color);
}
