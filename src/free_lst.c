/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:52:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/03 17:32:06 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <fcntl.h>
/*
static void	free_content_obj(t_obj *elem)
{
	ft_putstr("\n12");
	ft_putstr("13");
		free(&elem->pos.x);
	ft_putstr("14");
		free(&elem->pos.y);
	ft_putstr("15");
		free(&elem->pos.z);
	ft_putstr("16");
		free(&elem->dir.x);
	ft_putstr("17");
		free(&elem->dir.y);
	ft_putstr("18");
		free(&elem->dir.z);
	ft_putstr("19");
		free(&elem->size);
	ft_putstr("20");
		free(&elem->h);
	ft_putstr("21");
//		free(elem->i);
	ft_putstr("22");
		free(&elem->r);
	ft_putstr("23");
		free(&elem->g);
	ft_putstr("24");
		free(&elem->b);
	ft_putstr("25");
//		free(&elem->color);
}

static void	free_obj(t_obj *tmp)
{
	t_obj	*aobj;
	t_obj	*elem;

	aobj = tmp->next;
	while (aobj != NULL)
	{
		elem = aobj->next;
		free(&aobj->type);
		//free_content_obj(aobj);
		free(&aobj);
		aobj = elem;
	}
	if (tmp->next != NULL)
	{
		free(tmp->next);
		tmp->next = NULL;
	}
	//if (tmp->type)
	//	free(&tmp->type);
	tmp->type = ft_strdup("first");
}
static void	free_content_spot(t_spot *elem)
{
		free(&elem->pos.x);
		free(&elem->pos.y);
		free(&elem->pos.z);
		free(&elem->dir.x);
		free(&elem->dir.y);
		free(&elem->dir.z);
//		free(elem->i);
		free(&elem->r);
		free(&elem->g);
		free(&elem->b);
//		free(&elem->color);
}

static void	free_spot(t_spot *tmp)
{
	t_spot	*aspot;
	t_spot	*elem;

	aspot = tmp->next;
	while (aspot != NULL)
	{
		elem = aspot->next;
		free(&aspot->type);
		//free_content_obj(aobj);
		free(&aspot);
		aspot = elem;
	}
	if (tmp->next != NULL)
	{
		free(tmp->next);
		tmp->next = NULL;
	}
	//if (tmp->type)
	//	free(&tmp->type);
	//free_content_spot(tmp);
	tmp->type = ft_strdup("first");
}
*/
void	free_scene(t_obj *aobj, t_spot *aspot)
{
	ft_putstr("\n1");
	free(&aobj->type);
	aobj->type = ft_strdup("first");
	aobj->next = NULL;
	free(&aspot->type);
	aspot->type = ft_strdup("first");
	aspot->next = NULL;
//	free_obj(aobj);
	ft_putstr("\n1bis");
//	free_spot(aspot);
	ft_putstr("\nend free");
}
