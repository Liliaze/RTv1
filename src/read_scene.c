/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:19:53 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/27 17:45:42 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <fcntl.h>

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
		printf("o.x = %f|\n", aobj->pos.y);
		printf("o.x = %f|\n", aobj->pos.z);
		printf("dir.x = %f|\n", aobj->dir.x);
		printf("dir.y = %f|\n", aobj->dir.y);
		printf("dir.z = %f|\n", aobj->dir.z);
		printf("i = %f|\n", aobj->i);
		printf("rgb = [%d-%d-%d]\n", aobj->r, aobj->g, aobj->b);
		printf("color def = %d|\n", aobj->color);
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
		printf("o.x = %f|\n", aobj->pos.y);
		printf("o.x = %f|\n", aobj->pos.z);
		printf("dir.x = %f|\n", aobj->dir.x);
		printf("dir.y = %f|\n", aobj->dir.y);
		printf("dir.z = %f|\n", aobj->dir.z);
		printf("size = %f|\n", aobj->size);
		printf("hauteur = %f|\n", aobj->h);
		printf("rgb = [%d-%d-%d]\n", aobj->r, aobj->g, aobj->b);
		printf("color def = %d|\n", aobj->color);
		aobj = aobj->next;
	}
	printf ("TOTAL DE %d OBJECTS REGISTER\n", i);
}

static	int		nb_values(char	**values)
{
	int	i;
	int	j;

	i = 0;
	j = 12;
	while (values[i])
		i++;
	if (i == j)
		return (1);
	ft_display_error("A data is missing in map.");
	return (0);
}

static t_spot	*add_spot(t_spot *aspot, char **values)
{
	aspot->type = ft_strdup(values[0]);
	aspot->pos.x = ft_atod(values[1]);
	aspot->pos.y = ft_atod(values[2]);
	aspot->pos.z = ft_atod(values[3]);
	aspot->dir.x = ft_atod(values[4]);
	aspot->dir.y = ft_atod(values[5]);
	aspot->dir.z = ft_atod(values[6]);
	aspot->r = ft_atoi(values[9]);
	aspot->g = ft_atoi(values[10]);
	aspot->b = ft_atoi(values[11]);
	aspot->color = (aspot->r << 16) + (aspot->g << 8) + aspot->b;
	aspot->i = 0;
	aspot->next = NULL;
	return (aspot);
}

static t_obj	*add_object(t_obj *aobj, char **values)
{
	aobj->type = ft_strdup(values[0]);
	aobj->pos.x = ft_atod(values[1]);
	aobj->pos.y = ft_atod(values[2]);
	aobj->pos.z = ft_atod(values[3]);
	aobj->dir.x = ft_atod(values[4]);
	aobj->dir.y = ft_atod(values[5]);
	aobj->dir.z = ft_atod(values[6]);
	aobj->size = ft_atod(values[7]);
	aobj->h = ft_atod(values[8]);
	aobj->r = ft_atoi(values[9]);
	aobj->g = ft_atoi(values[10]);
	aobj->b = ft_atoi(values[11]);
	aobj->color = (aobj->r << 16) + (aobj->g << 8) + aobj->b;
	if (!(ft_strcmp(aobj->type, "sphere")))
		aobj->smash = &smash_sphere;
	else if (!(ft_strcmp(aobj->type, "plan")))
		aobj->smash = &smash_plan;
	else if (!(ft_strcmp(aobj->type, "cyl")))
		aobj->smash = &smash_cylindre;
	else if (!(ft_strcmp(aobj->type, "cone")))
		aobj->smash = &smash_cone;
	else
		ft_display_error("A requested form in your map does not exist.");
	aobj->next = NULL;
	return (aobj);
}

static int	to_create_lst(t_obj *aobj, t_spot *aspot, t_obj *save_head_obj, char **values)
{
	t_spot	*save_head_spot;

	save_head_spot = aspot;
	save_head_obj = aobj;
	if (!(ft_strcmp(values[0], "spot")))
	{
		if (ft_strcmp(save_head_spot->type, "first"))
		{
			while (save_head_spot->next != NULL)
				save_head_spot = save_head_spot->next;
			save_head_spot->next = (t_spot *)ft_memalloc(sizeof(t_spot)); 
			save_head_spot = save_head_spot->next;
		}
		save_head_spot = add_spot(save_head_spot, values);
		return (1);
	}
	if (ft_strcmp(save_head_obj->type, "first"))
	{
		while (save_head_obj->next != NULL)
			save_head_obj = save_head_obj->next;
		save_head_obj->next = (t_obj *)ft_memalloc(sizeof(t_obj)); 
		save_head_obj = save_head_obj->next;
	}
	save_head_obj = add_object(save_head_obj, values);
	return (1);
}

int			read_scene(t_obj *aobj, t_spot *aspot, t_obj *acur, char *scene)
{
	int		ret;
	int		fd;
	char	*line;
	char	**values;

	ret = 1;
	if ((fd = open(scene, O_RDONLY)) == -1)
		ft_display_error("Please join a correct map file");
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		values = ft_strsplit(line, '\t');
		if (values[0][0] != '/' && values != NULL && nb_values(values))
			to_create_lst(aobj, aspot, acur, values);
		free_line_and_values(line, values);
	}
	if (!(ft_strcmp(aobj->type, "first")) || ret == -1)
		ft_display_error("Bad ARGV or Not object in your map."); // si multi argu a ecrire sur la fenetre et ne pas lancer le raytracing !!!!
	if (!(ft_strcmp(aspot->type, "first")))
	{
		free(aspot->type);
		ft_memdel((void**)&(aspot));
	}
	print_object(aobj); //a retirer a la fin
	print_spot(aspot); //a retirer a la fin
	close(fd);
	return (1);
}
