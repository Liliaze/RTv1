/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:31:14 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/06 17:24:44 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "color_key_mask.h"
# include <stdio.h> // A SUP AVANT RENDU DEBUG
# include <stdlib.h>

# define MLX		awin->mlx
# define WIN		awin->win
# define MAP		awin->av
# define WINW		800
# define WINH		640
# define COEFW		(double)WINW / ((double)WINW * 100)
# define COEFH		(double)WINH / ((double)WINH * 100)

typedef struct	s_windows
{
	int			padding;
	int			width;
	int			height;
	int			ac;
	char		**av;
	void		*mlx;
	void		*win;
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
	t_v3d		pos;
	t_v3d		dir_x;
	t_v3d		dir_y;
	t_v3d		dir_z;
}				t_cam;

typedef struct	s_rayon
{
	t_v3d		pos;
	t_v3d		dir;
	t_v3d		i;
	double		t;
	int			padding;
	int			check_spot;
}				t_ray;


typedef struct	s_spot
{
	char		*type;
	t_v3d		pos;
	t_v3d		dir;
	int			r;
	int			g;
	int			b;
	int			color;
	//double		i;
	struct 	s_spot	*next;
}				t_spot;

typedef struct	s_object
{
	char			*type;
	t_v3d			pos;
	t_v3d			dir;
	double			size;
	double			h;
	int				r;
	int				g;
	int				b;
	int				color;
	int				(*smash)(struct s_object *, t_ray *);
	int				(*norm)(struct s_object *, t_ray *);
	struct s_object	*next;
}				t_obj;

typedef struct	s_all
{
	char		*scene;
	short		in_menu;
	short		hook;
	short		nb_spot;
	short		nb_obj;
	int			color;
	int			padding;
	double		dist;
	t_v3d		*ai;
	t_win		*awin;
	t_img		*aimg;
	t_cam		*acam;
	t_ray		*aray;
	t_obj		*aobj;
	t_spot		*aspot;
}				t_all;

void	go_menu(t_all *all, int key);
void	free_scene(t_obj *aobj, t_spot *aspot, int nb_obj, int nb_spot);
void	init_cam(t_cam *acam);
int		read_scene(t_all *all);
int		ft_loop(t_all *all);
void	ray_tracing(t_all *all);
void	define_pixel_target(int x, int y, t_cam *acam, t_ray *aray);
void	define_ray_dir(t_ray *aray);
int		norm_plan(t_obj *plan, t_ray *aray);
int		norm_sphere(t_obj *sphere, t_ray *aray);
int		norm_cyl(t_obj *cyl, t_ray *aray);
int		norm_cone(t_obj *cyl, t_ray *aray);
int		smash_plan(t_obj *plan, t_ray *aray);
int		smash_sphere(t_obj *sphere, t_ray *aray);
int		smash_cyl(t_obj *cyl, t_ray *aray);
int		smash_cone(t_obj *cyl, t_ray *aray);
void	color_all_pixel(int color, char *data, int last_pixel);
void	color_one_pixel_secure(int color, t_img *aimg, int x, int y);
void	printv(t_v3d v); // a retirer end
void	vector_translate(t_v3d *a, t_v3d b, double coef);
void	vector_normalize(t_v3d *v);
double	vector_dist(t_v3d a, t_v3d b);
t_v3d	*vector_sub(t_v3d *a, t_v3d *b);
t_v3d	*vector_subtmp(t_v3d *a, t_v3d *b);
t_v3d	*set_to(t_v3d *a, t_v3d *b);
double	vector_dot(t_v3d *a, t_v3d *b);
t_v3d  *scalar_multiply(t_v3d *a, double amount);
#endif
