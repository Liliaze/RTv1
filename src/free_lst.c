/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:52:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/06 17:59:26 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <fcntl.h>

static t_spot	*free_lst_spot(t_spot *liste)
{
	t_spot	*tmp;
	t_spot	*ptmp;

	tmp		= liste->next;
	ptmp	= liste;
	while (tmp != NULL)
	{
		ptmp = tmp;
		tmp = tmp->next;
		free(ptmp->type);
		free(ptmp);
	}
	free(liste->type);
	liste->type = ft_strdup("first");
	liste->next = NULL;
	return (liste);
}

static t_obj	*free_lst_obj(t_obj *liste)
{
	t_obj	*tmp;
	t_obj	*ptmp;

	ptmp	= liste;
	tmp = liste->next;
	while (tmp != NULL)
	{
		ptmp = tmp;
		tmp = tmp->next;
		free(ptmp->type);
		free(ptmp);
	}
	free(liste->type);
	liste->type = ft_strdup("first");
	liste->next = NULL;
	return (liste);
}

void	free_scene(t_obj *aobj, t_spot *aspot, int nb_obj, int nb_spot)
{
	if (nb_spot)
		aspot = free_lst_spot(aspot);
	if (nb_obj)
		aobj = free_lst_obj(aobj);
}
