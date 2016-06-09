/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:19:53 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/09 11:04:03 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <fcntl.h>
#include "mlx.h"

static void	*add_obj(t_obj *aobj, char **val)
{
	free(aobj->type);
	aobj->type = ft_strdup(val[0]);
	aobj->pos.x = ft_atod(val[1]);
	aobj->pos.y = ft_atod(val[2]);
	aobj->pos.z = ft_atod(val[3]);
	aobj->dir.x = ft_atod(val[4]);
	aobj->dir.y = ft_atod(val[5]);
	aobj->dir.z = ft_atod(val[6]);
	aobj->size = ft_atod(val[7]);
	aobj->c.r = ft_atoi(val[9]);
	aobj->c.g = ft_atoi(val[10]);
	aobj->c.b = ft_atoi(val[11]);
	if (!(ft_strcmp(aobj->type, "sphere")))
		aobj->smash = &smash_sphere;
	else if (!(ft_strcmp(aobj->type, "plan")))
		aobj->smash = &smash_plan;
	else if (!(ft_strcmp(aobj->type, "cyl")))
		aobj->smash = &smash_cyl;
	else if (!(ft_strcmp(aobj->type, "cone")))
		aobj->smash = &smash_cone;
	else
		ft_display_error("A requested form in your map does not exist.");
	aobj->h = ft_atod(val[8]);
	aobj->next = NULL;
	return (aobj);
}

static void	*add_spot(t_spot *aspot, short *nb, char **val)
{
	(*nb)++;
	free(aspot->type);
	aspot->type = ft_strdup(val[0]);
	aspot->pos.x = ft_atod(val[1]);
	aspot->pos.y = ft_atod(val[2]);
	aspot->pos.z = ft_atod(val[3]);
	aspot->dir.x = ft_atod(val[4]);
	aspot->dir.y = ft_atod(val[5]);
	aspot->dir.z = ft_atod(val[6]);
	aspot->c.r = ft_atoi(val[9]);
	aspot->c.g = ft_atoi(val[10]);
	aspot->c.b = ft_atoi(val[11]);
	aspot->next = NULL;
	return (aspot);
}

static void	to_create_lst(t_all *all, char **val)
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
		save_head_spot = add_spot(save_head_spot, &all->nb_s, val);
	}
	else if (ft_strcmp(save_head_obj->type, "first"))
	{
		while (save_head_obj->next != NULL)
			save_head_obj = save_head_obj->next;
		save_head_obj->next = (t_obj *)ft_memalloc(sizeof(t_obj));
		save_head_obj = save_head_obj->next;
	}
	if (ft_strcmp(val[0], "spot") && (all->nb_o += 1))
		save_head_obj = add_obj(save_head_obj, val);
}

int			read_scene(t_all *all)
{
	int		ret;
	int		fd;
	char	*line;
	char	**val;

	ret = 1;
	all->nb_s = 0;
	all->nb_o = 0;
	if ((fd = open(all->scene, O_RDONLY)) == -1)
		ft_display_error("Please join a correct map file");
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		val = ft_strsplit(line, '\t');
		if (val[0][0] != '/' && (ft_tablen(val) == 12))
			to_create_lst(all, val);
		else if (val[0][0] != '/' && !(ft_tablen(val) == 12))
			ft_display_error("A data is missing in map.");
		free_line_and_values(line, val);
	}
	if (!(ft_strcmp(all->aobj->type, "first")) || ret == -1)
		ft_display_error("Bad ARGV or Not object in your map. Press ENTER");
	close(fd);
	return (1);
}
