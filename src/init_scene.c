inline static init_cam(t_cam *acam)
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
{}[]

static int	add_object(t_obj *aobj, char **line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (aobj != NULL)
		return (add_object(obj->next));
	if (line[i][j] == '/')
		return (0);
	aobj = (t_obj *)ft_memmalloc(sizeof(t_obj)); 
	aobj->type = ft_strdup(line[0]);
	aobj->origin.x = ft_atoi(line[1]);
	aobj->origin.y = ft_atoi(line[2]);
	aobj->origin.z = ft_atoi(line[3]);
	aobj->dir.x = 0;
	aobj->dir.y = 0;
	aobj->dir.z = 0;
	aobj->type = ft_strcopy(line[][]);
	aobj->type = ft_strcopy(line[][]);
	aobj->type = ft_strcopy(line[][]);
		[]
		
{}[]
{}[]
		
	return (1);
}

int		init_scene(t_obj *aobj, int *nb_object, char *scene)
{
	int		i;
	int		ret;
	int		fd;
	char	*line;
	char	**values;

	i = -1;
	ret = 1;
	aobj = NULL;
	if ((fd = open(scene, O_RDONLY)) == -1)
		display_error("Please join a correct scene file\n");
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		values = ft_strsplit(line, ' ');
		add_object(aobj, values);
		free(line);
	}
	if (ret == -1)
		display_error("GNL on scene failed\n");
	amap->map[i] = NULL;
	check_map(amap);
	init_cam(all->acam);
	return (1);
}
}

