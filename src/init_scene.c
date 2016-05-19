/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:19:53 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/19 16:59:13 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <fcntl.h>

inline static void init_cam(t_cam *acam)
{
	acam->origin.x = 0;
	acam->origin.y = -100;
	acam->origin.z = 0;
	acam->dir_x.x = 1;
	acam->dir_x.y = 0;
	acam->dir_x.z = 0;
	acam->dir_y.x = 0;
	acam->dir_y.y = 1;
	acam->dir_y.z = 0;
	acam->dir_z.x = 0;
	acam->dir_z.y = 0;
	acam->dir_z.z = 1;
}

void	print_object(t_obj *tmp, int *nb_object)
{
	t_obj	*aobj;
	
	aobj = tmp;
	while (aobj != NULL)
	{
		printf ("======= %s =======\n", aobj->type);
		printf ("o.x = %f|\n", aobj->origin.x);
		printf ("o.x = %f|\n", aobj->origin.y);
		printf ("o.x = %f|\n", aobj->origin.z);
		printf ("dir.x = %f|\n", aobj->dir.x);
		printf ("dir.y = %f|\n", aobj->dir.y);
		printf ("dir.z = %f|\n", aobj->dir.z);
		printf ("size = %f|\n", aobj->size);
		printf ("rgb = [%d-%d-%d]\n", aobj->r, aobj->g, aobj->b);
		printf ("color def = %d|\n", aobj->color);
		//printf ("ft_ptr = %p|\n", aobj->smash);
		aobj = aobj->next;
	}
	printf ("TOTAL DE %d OBJECTS REGISTER\n", *nb_object);
}

static t_obj	*add_object(t_obj *aobj, int *nb_object, char **line)
{
	aobj->type = ft_strdup(line[0]);
	aobj->origin.x = ft_atoi(line[1]);
	aobj->origin.y = ft_atoi(line[2]);
	aobj->origin.z = ft_atoi(line[3]);
	aobj->dir.x = ft_atoi(line[4]);
	aobj->dir.y = ft_atoi(line[5]);
	aobj->dir.z = ft_atoi(line[6]);
	aobj->size = ft_atoi(line[7]);
	aobj->r = ft_atoi(line[8]);
	aobj->g = ft_atoi(line[9]);
	aobj->b = ft_atoi(line[10]);
	aobj->color = (aobj->r << 16) + (aobj->g << 8) + aobj->b;
	if (!(ft_strcmp(aobj->type, "sphere")))
		aobj->smash = &smash_sphere;
	else
		aobj->smash = &smash_plan;
	aobj->next = NULL;
	(*nb_object)++;
	return (aobj);
}

int		init_scene(t_cam *acam, t_obj *aobj, int *nb_object, char *scene)
{
	int		ret;
	int		fd;
	char	*line;
	char	**values;
	t_obj	*save_head;

	ret = 1;
	init_cam(acam);
	save_head = aobj;
	*nb_object = 0;
	if ((fd = open(scene, O_RDONLY)) == -1)
		ft_display_error("Please join a correct scene file\n");
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		values = ft_strsplit(line, '\t');
		if (values[0][0] != '/' && values != NULL)
		{
			if (*nb_object != 0)
			{
				save_head->next = (t_obj *)ft_memalloc(sizeof(t_obj)); 
				save_head = save_head->next;
			}
			save_head = add_object(save_head, nb_object, values);
		}
		free(line);
	}
	if (ret == -1)
		ft_display_error("GNL on scene failed\n");
	save_head = aobj;
	print_object(save_head, nb_object); //a faire et retirer a la fin
	close(fd);
	return (1);
}
