/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:03:31 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/08 13:08:01 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_new;
	t_list	*elem_before;
	t_list	*new_elem;

	if (lst && (*f))
	{
		begin_new = (*f)(lst);
		lst = lst->next;
		elem_before = begin_new;
		while (lst)
		{
			new_elem = (*f)(lst);
			elem_before->next = new_elem;
			lst = lst->next;
			elem_before = new_elem;
		}
		elem_before = NULL;
	}
	else
		return (NULL);
	return (begin_new);
}
