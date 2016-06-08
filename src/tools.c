/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 13:33:26 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/08 16:11:37 by dboudy           ###   ########.fr       */
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

void	color_one_px_sec(int color, t_img *img, int x, int y)
{
	int *tmp;
	int pixel;

	tmp = (int*)(void*)img->image;
	pixel = x + y * img->size_line;
	if (x >= 0 && x < img->size_line && y >= 0
			&& y < (img->last_pixel / img->size_line))
		tmp[pixel] = color;
}
