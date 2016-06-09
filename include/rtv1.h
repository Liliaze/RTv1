/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:31:14 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/09 12:35:00 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "color_key_mask.h"
# include "libft.h"
# include <math.h>

# define MLX		awin->mlx
# define WIN		awin->win
# define MAP		awin->av
# define WINW		800
# define WINH		640
# define COEFW		(double)WINW / ((double)WINW * 100)
# define COEFH		(double)WINH / ((double)WINH * 100)

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_vector3d
{
	double			x;
	double			y;
	double			z;
}					t_v3d;

typedef struct		s_windows
{
	int				padding;
	int				width;
	int				height;
	int				ac;
	char			**av;
	void			*mlx;
	void			*win;
}					t_win;

typedef struct		s_image
{
	void			*id;
	char			*image;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
	int				last_pixel;
}					t_img;

typedef struct		s_camera
{
	t_v3d			pos;
	t_v3d			dir_x;
	t_v3d			dir_y;
	t_v3d			dir_z;
}					t_cam;

typedef struct		s_rayon
{
	t_v3d			pos;
	t_v3d			dir;
	t_v3d			i;
	double			t;
	int				padding;
	int				check_spot;
}					t_ray;

typedef struct		s_spot
{
	char			*type;
	t_v3d			pos;
	t_v3d			dir;
	t_rgb			c;
	int				pad;
	struct s_spot	*next;
}					t_spot;

typedef struct		s_object
{
	t_rgb			c;
	int				pad;
	t_v3d			pos;
	t_v3d			dir;
	double			size;
	double			h;
	char			*type;
	int				(*smash)(struct s_object *, t_ray *);
	struct s_object	*next;
}					t_obj;

typedef struct		s_all
{
	short			in_menu;
	short			hook;
	short			nb_s;
	short			nb_o;
	double			dist;
	char			*scene;
	t_rgb			*ac;
	t_v3d			*ai;
	t_win			*awin;
	t_img			*aimg;
	t_cam			*acam;
	t_ray			*aray;
	t_obj			*aobj;
	t_spot			*aspot;
}					t_all;

int					ft_loop(t_all *all);
void				go_menu(t_all *all, int key);
void				free_scene(t_obj *aobj,
						t_spot *aspot, int nb_obj, int nb_spot);
void				init_cam(t_cam *acam);
int					read_scene(t_all *all);
void				ray_tracing(t_all *all);
int					check_spot(t_all *all, int color);
int					smash_plan(t_obj *plan, t_ray *aray);
int					smash_sphere(t_obj *sphere, t_ray *aray);
int					smash_cyl(t_obj *cyl, t_ray *aray);
int					smash_cone(t_obj *cyl, t_ray *aray);
void				color_all_pixel(int color, char *data, int last_pixel);
void				color_one_px_sec(int color, t_img *aimg, int x, int y);
void				vector_translate(t_v3d *a, t_v3d b, double coef);
void				vector_normalize(t_v3d *v);
double				vector_dist(t_v3d a, t_v3d b);
t_v3d				*vector_add(t_v3d *a, t_v3d *b);
t_v3d				*vector_sub(t_v3d *a, t_v3d *b);
t_v3d				*set_to(t_v3d *a, t_v3d *b);
double				vector_dot(t_v3d *a, t_v3d *b);
t_rgb				*rgb_scale_max(t_rgb *src);
t_rgb				*rgb_coef(t_rgb *src, double coef);
t_rgb				*rgb_set_to(t_rgb *dest, t_rgb *src);
int					add_int_rgb(int color, int color2);
int					rgb_to_int(t_rgb *src);
int					rgb_to_int_coef(t_rgb *src, double coef);

#endif
