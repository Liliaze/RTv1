/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:19:53 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/23 17:15:58 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <fcntl.h>

inline void init_cam(t_cam *acam)
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
		printf ("hauteur = %f|\n", aobj->h);
		printf ("rgb = [%d-%d-%d]\n", aobj->r, aobj->g, aobj->b);
		printf ("color def = %d|\n", aobj->color);
		aobj = aobj->next;
	}
	printf ("TOTAL DE %d OBJECTS REGISTER\n", *nb_object);
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

static t_obj	*add_object(t_obj *aobj, int *nb_object, char **line)
{
	aobj->type = ft_strdup(line[0]);
	aobj->origin.x = ft_atod(line[1]);
	aobj->origin.y = ft_atod(line[2]);
	aobj->origin.z = ft_atod(line[3]);
	aobj->dir.x = ft_atod(line[4]);
	aobj->dir.y = ft_atod(line[5]);
	aobj->dir.z = ft_atod(line[6]);
	aobj->size = ft_atod(line[7]);
	aobj->h = ft_atod(line[8]);
	aobj->r = ft_atoi(line[9]);
	aobj->g = ft_atoi(line[10]);
	aobj->b = ft_atoi(line[11]);
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
	(*nb_object)++;
	return (aobj);
}

int		init_scene(t_obj *aobj, t_obj *acur, int *nb_object, char *scene)
{
	int		ret;
	int		fd;
	char	*line;
	char	**values;

	ret = 1;
	acur = aobj;
	*nb_object = 0;
	if ((fd = open(scene, O_RDONLY)) == -1)
		ft_display_error("Please join a correct map file");
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		values = ft_strsplit(line, '\t');
		if (values[0][0] != '/' && values != NULL && nb_values(values))
		{
			if (*nb_object != 0)
			{
				acur->next = (t_obj *)ft_memalloc(sizeof(t_obj)); 
				acur = acur->next;
			}
			acur = add_object(acur, nb_object, values);
		}
		free(line);
	}
	if (ret == -1)
		ft_display_error("Bad ARGV, GNL on map failed");
	acur = aobj;
	print_object(acur, nb_object); //a faire et retirer a la fin
	close(fd);
	return (1);
}
