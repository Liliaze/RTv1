/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smash_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:32:02 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/13 16:42:51 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include "libft.h"

void	init_sphere(t_obj *sphere) // tmp
{
	t_obj	*new;
	t_obj	*new2;
	t_obj	*new3;

	sphere->type = "sphere";
	sphere->radius.x = 450;
	sphere->pos.x = 50;
	sphere->pos.y = 100;
	sphere->pos.z = 5;
	sphere->color = RED;
	
	new3 = (t_obj *)ft_memalloc(sizeof(t_obj));
	new3->type = "sphere";
	new3->radius.x = 450;
	new3->pos.x = 150;
	new3->pos.y = 150;
	new3->pos.z = 5;
	new3->color = YELLOW;
	
	new2 = (t_obj *)ft_memalloc(sizeof(t_obj));
	new2->type = "sphere";
	new2->radius.x = 450;
	new2->pos.x = 200;
	new2->pos.y = 150;
	new2->pos.z = 5;
	new2->color = GREEN;
	
	new = (t_obj *)ft_memalloc(sizeof(t_obj));
	new->type = "plan";
	new->size.x = 1;
	new->size.y = 0;
	new->size.z = 0;
	new->pos.x = 0;
	new->pos.y = WINW / 2;
	new->pos.z = 1;
	new->color = BLUE;
	
	new3->next = NULL;
	new2->next = new3;
	new->next = new2;
	sphere->next = new;
}

int		smash(t_obj *obj, t_ray *aray, double *t)
{
	int	ret;

	ret = 0;
	if (!ft_strcmp(obj->type, "sphere"))
		ret = smash_sphere(obj, aray, t);
	else if (!ft_strcmp(obj->type, "plan"))
		ret = smash_plan(obj, aray, t);
	return (ret);
}

int		smash_plan(t_obj *plan, t_ray *aray, double *t)
{
	t_vec3d		*cpy;
	double		tmp[3];

	cpy = vector_copy(&plan->pos);
	cpy = vector_sub(cpy, &aray->origin);
	tmp[0] = vector_dot(cpy, &aray->origin);
	tmp[1] = vector_dot(cpy, &aray->dir);
	tmp[2] = -(tmp[0] / tmp[1]);
	if (tmp[2] > -0.01 && tmp[2] < *t)
	{
		*t = tmp[2];
		return (1);
	}
	return (0);
}

int		smash_sphere(t_obj *sphere, t_ray *aray, double *t)
{
	int			ret;
	double		tmp[3];
	double		smash;
	t_vec3d		*dist;
	
	ret = 0;
	dist = vector_copy(&sphere->pos);
	dist = vector_sub(dist, &aray->origin);
	tmp[0] = vector_dot(&aray->dir, dist);
	smash = (tmp[0] * tmp[0]) - vector_dot(dist, dist)
		+ (sphere->radius.x * sphere->radius.x);
	if (smash < 0.0)
		return (ret);	
	tmp[1] = tmp[0] - sqrt(smash);
	tmp[2] = tmp[0] + sqrt(smash);
	if (tmp[1] > 0.01 && tmp[1] < *t)
	{
		*t = tmp[1];
		ret = 1;
	}
	if (tmp[2] > 0.01 && tmp[2] < *t)
	{
		*t = tmp[2];
		ret = 1;
	}
	return (ret);
}
