/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:31:14 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/18 19:06:54 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
#define RTV1_H

#include "color_key_mask.h"
#include <stdio.h> // A SUP AVANT RENDU DEBUG
#include <stdlib.h>

#define MAX_DIST	200000
#define WINW		1080
#define WINH		800
#define FOV		30

typedef struct	s_windows
{
	void		*mlx;
	void		*win;
	char		*title;
	int			width;
	int			height;
}				t_win;

typedef struct	s_image
{
	void		*id;
	char		*image;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
	int			last_pixel;
}				t_img;

typedef struct	s_vector3d
{
	double		x;
	double		y;
	double		z;
}				t_v3d;

typedef struct	s_camera
{
	t_v3d		origin;
	t_v3d		dir_x;
	t_v3d		dir_y;
	t_v3d		dir_z;
	double		dist_focale;
}				t_cam;

typedef struct	s_rayon
{
	t_v3d		origin; // origine 
	t_v3d		dir; // direction
	t_v3d		target;
	double		t; //distance : inconnue a trouver
}				t_ray;

/*
typedef struct	s_texture
{
	int		object_color[4]; // 0 = ambiant_color, 1 = diffuse_color, 2 = reflex_color, 3 = specul_color;
	int		coef_color[4];
	int		opacite;
}				t_text;
*/

typedef struct	s_object
{
	char			*type;
	t_v3d			origin;
	t_v3d			dir;
	t_v3d			dir2;
	double			size;
	double			dist;
	int				r;
	int				g;
	int				b;
	int				color;
	int				(*smash)(struct s_object *, t_ray *);
	struct s_object	*next;
}				t_obj;

typedef struct	s_all
{
	int			nb_object;
	int			color;
	double		dist;
	t_win		*awin;
	t_img		*aimg;
	t_v3d		*av3d;
	t_cam		*acam;
	t_ray		*aray;
	t_obj		*aobj;
	t_obj		*acur;
}				t_all;

int		test(int nb);
int		ft_loop(t_all *all);
int		init_scene(t_cam *acam, t_obj *aobj, int *nb_obj, char *name_scene);
void	init_sphere(t_obj *sphere);
void	define_pixel_target(int x, int y, t_cam *acam, t_ray *aray);
void	define_ray_dir(t_ray *aray);
void	color_all_pixel(int color, char *data, int last_pixel);
void	color_one_pixel_secure(int color, t_img *aimg, int x, int y);
void	ray_tracing(t_all *all);
int		smash_check(t_all *all);
int		smash_plan(t_obj *plan, t_ray *aray);
int		smash_sphere(t_obj *sphere, t_ray *aray);
void	vector_normalize(t_v3d *v);
t_v3d	*vector_sub(t_v3d *a, t_v3d *b);
void	vector_mult(t_v3d *a, t_v3d *b);
void	vector_translate(t_v3d *a, t_v3d *b, double coef);
double	vector_dot(t_v3d *a, t_v3d *b);
t_v3d	*vector_copy(t_v3d *v);
#endif
