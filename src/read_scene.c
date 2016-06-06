/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:19:53 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/06 17:36:54 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <fcntl.h>
#include "mlx.h"
#include "color_key_mask.h"

static void	print_spot(t_spot *tmp)
{
	t_spot	*aobj;
	int		i;

	aobj = tmp;
	i = 0;
	printf("\n====== SPOT ===\n");// aretirer
	while (aobj != NULL && ++i)
	{
		printf("======= %s =======\n", aobj->type);
		printf("o.x = %f|\n", aobj->pos.x);
		printf("o.y = %f|\n", aobj->pos.y);
		printf("o.z = %f|\n", aobj->pos.z);
		printf("dir.x = %f|\n", aobj->dir.x);
		printf("dir.y = %f|\n", aobj->dir.y);
		printf("dir.z = %f|\n", aobj->dir.z);
		//		printf("i = %f|\n", aobj->i);
		printf("rgb = [%d-%d-%d]\n", aobj->r, aobj->g, aobj->b);
		aobj = aobj->next;
	}
	printf ("TOTAL DE %d SPOTS REGISTER\n", i);
}

static void	print_object(t_obj *tmp)
{
	t_obj	*aobj;
	int		i;

	aobj = tmp;
	i = 0;
	while (aobj != NULL && ++i)
	{
		printf("======= %s =======\n", aobj->type);
		printf("o.x = %f|\n", aobj->pos.x);
		printf("o.y = %f|\n", aobj->pos.y);
		printf("o.z = %f|\n", aobj->pos.z);
		printf("dir.x = %f|\n", aobj->dir.x);
		printf("dir.y = %f|\n", aobj->dir.y);
		printf("dir.z = %f|\n", aobj->dir.z);
		printf("size = %f|\n", aobj->size);
		printf("hauteur = %f|\n", aobj->h);
		printf("rgb = [%d-%d-%d]\n", aobj->r, aobj->g, aobj->b);
		aobj = aobj->next;
	}
	printf ("TOTAL DE %d OBJECTS REGISTER\n", i);
}

static	void	add_pnt_fnt(t_obj *aobj, char *type)
{
	if (!(ft_strcmp(type, "sphere")))
	{
		aobj->smash = &smash_sphere;
		aobj->norm = &norm_sphere;
	}
	else if (!(ft_strcmp(type, "plan")))
	{
		aobj->smash = &smash_plan;
		aobj->norm = &norm_sphere;
	}
	else if (!(ft_strcmp(type, "cyl")))
	{
		aobj->smash = &smash_cyl;
		aobj->norm = &norm_cyl;
	}
	else if (!(ft_strcmp(type, "cone")))
	{
		aobj->smash = &smash_cone;
		aobj->norm = &norm_cone;
	}
	else
		ft_display_error("A requested form in your map does not exist.");
}

static void	*add_obj(t_obj *aobj, short *nb, char **val)
{
	(*nb)++;
	aobj->type = ft_strdup(val[0]);
	aobj->pos.x = ft_atod(val[1]);
	aobj->pos.y = ft_atod(val[2]);
	aobj->pos.z = ft_atod(val[3]);
	aobj->dir.x = ft_atod(val[4]);
	aobj->dir.y = ft_atod(val[5]);
	aobj->dir.z = ft_atod(val[6]);
	aobj->size = ft_atod(val[7]);
	aobj->r = ft_atoi(val[9]);
	aobj->g = ft_atoi(val[10]);
	aobj->b = ft_atoi(val[11]);
	add_pnt_fnt(aobj, aobj->type);
	aobj->h = ft_atod(val[8]);
	aobj->next = NULL;
	return (aobj);
}

static void	*add_spot(t_spot *aspot, short *nb, char **val)
{
	(*nb)++;
	aspot->type = ft_strdup(val[0]);
	aspot->pos.x = ft_atod(val[1]);
	aspot->pos.y = ft_atod(val[2]);
	aspot->pos.z = ft_atod(val[3]);
	aspot->dir.x = ft_atod(val[4]);
	aspot->dir.y = ft_atod(val[5]);
	aspot->dir.z = ft_atod(val[6]);
	aspot->r = ft_atoi(val[9]);
	aspot->g = ft_atoi(val[10]);
	aspot->b = ft_atoi(val[11]);
	aspot->next = NULL;
	return (aspot);
}

static int	to_create_lst(t_all *all, char **val)
{
	t_spot	*save_head_spot;
	t_obj	*save_head_obj;

	save_head_spot = all->aspot;
	save_head_obj = all->aobj;
	if (!(ft_strcmp(val[0], "spot")))
	{
		if (ft_strcmp(save_head_spot->type, "first"))
		{
			while (save_head_spot->next != NULL)
				save_head_spot = save_head_spot->next;
			save_head_spot->next = (t_spot *)ft_memalloc(sizeof(t_spot)); 
			save_head_spot = save_head_spot->next;
		}
		else
		free(save_head_spot->type);
		save_head_spot = add_spot(save_head_spot, &all->nb_spot, val);
		return (1);
	}
	if (ft_strcmp(save_head_obj->type, "first"))
	{
		while (save_head_obj->next != NULL)
			save_head_obj = save_head_obj->next;
		save_head_obj->next = (t_obj *)ft_memalloc(sizeof(t_obj)); 
		save_head_obj = save_head_obj->next;
	}
	else
	free(save_head_obj->type);
	save_head_obj = add_obj(save_head_obj, &all->nb_obj, val);
	return (1);
}

int			read_scene(t_all *all)
{
	int		ret;
	int		fd;
	char	*line;
	char	**val;

	ret = 1;
	all->nb_obj = 0; //tmp !
	all->nb_spot = 0;
	if ((fd = open(all->scene, O_RDONLY)) == -1)
		ft_display_error("Please join a correct map file");
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		val = ft_strsplit(line, '\t');
		if (val[0][0] != '/')
		{
			if (ft_tablen(val) == 12)
				to_create_lst(all, val);
			else
				ft_display_error("A data is missing in map.");
		}
		free_line_and_values(line, val);
	}
	if (!(ft_strcmp(all->aobj->type, "first")) || ret == -1)
		mlx_string_put(all->MLX, all->WIN, (WINW - 480) / 2, WINH / 2,
				RED, "Bad ARGV or Not object in your map. Press ENTER");
	if (all->nb_obj)
		print_object(all->aobj); // warning
	if (all->nb_spot)
		print_spot(all->aspot); //warning
	close(fd);
	return (1);
}
