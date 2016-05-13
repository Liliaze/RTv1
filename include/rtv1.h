/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:31:14 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/13 16:42:55 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
#define RTV1_H

#include "color_key_mask.h"
#include <stdio.h> // A SUP AVANT RENDU DEBUG
#include <stdlib.h>

#define MAX_DIST 200000
#define WINW	 1080
#define WINH	 800

typedef struct	s_windows
{
	void		*mlx;
	void		*win;
	char		*title_win;
	int			wwidth;
	int			wheight;
}				t_win;

typedef struct	s_image
{
	void		*id;
	char		*image;
	int			iwidth;
	int			iheight;
	int			bpp;
	int			size_line;
	int			endian;
	int			last_pixel;
}				t_image;

typedef struct	s_vector3d
{
	double		x;
	double		y;
	double		z;
}				t_vec3d;

typedef struct	s_camera
{
	double		fov;
	t_vec3d		pos;
	t_vec3d		rot;
	t_vec3d		res;
	double		dist_focale;
}				t_cam;

typedef struct	s_rayon
{
	t_vec3d		target_pixel;
	t_vec3d		origin; // origine : 
	t_vec3d		dir; // direction
	//int			t; //distance : inconnue a trouver
}				t_ray;

/*
typedef struct	s_texture
{
	int		object_color[4]; // 0 = ambiant_color, 1 = diffuse_color, 2 = reflex_color, 3 = specul_color;
	int		coef_color[4];
	int		opacite;
}				t_texture;
*/

typedef struct	s_object
{
	char			*type;
	t_vec3d			pos;
	t_vec3d			radius;
	t_vec3d			size;
	int				color;
	int				padding;
	struct s_object	*next;
}				t_obj;

typedef struct	s_pixel
{
	int		x_final;
	int		y_final;
	int		color_to_pix;
}				t_pixel;

typedef struct	s_all
{
	t_win		*awin;
	t_image		*aimage;
	t_cam		*acam;
	t_ray		*aray;
	t_obj		*aobj;
	t_pixel		*apixel;
}				t_all;

int		test(int nb);
int		ft_loop(t_all *all);
void	ray_tracing(t_all *all);
int		smash(t_obj *obj, t_ray *aray, double *t);
int		smash_plan(t_obj *plan, t_ray *aray, double *t);
int		smash_sphere(t_obj *sphere, t_ray *aray, double *t);
void	vector_normalize(t_vec3d *v);
double	vector_dot(t_vec3d *a, t_vec3d *b);
t_vec3d	*vector_copy(t_vec3d *v);
t_vec3d	*vector_sub(t_vec3d *a, t_vec3d *b);
void	init_camera(t_ray *aray, t_cam *acam, t_win *awin);
void	init_sphere(t_obj *sphere);
void	define_pixel_target(int x, int y, t_cam *acam, t_ray *aray);
void	define_ray_dir(t_ray *aray);
void	color_all_pixel(int color, char *data, int last_pixel);
void	color_one_pixel_secure(int color, t_image *aimage, int x, int y);
/*void	draw_cercle(t_image *aimage, t_obj *aobj);
void	fill_shape(t_image *aimage, int x, int y, int color);
void	fill_degrade_shape(t_image *aimage, int x, int y, int color_stop, int color_put);
int		degrade(int color);
*/
#endif
