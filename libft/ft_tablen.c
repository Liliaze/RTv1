/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:38:15 by dboudy            #+#    #+#             */
/*   Updated: 2016/06/09 11:39:47 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tablen(char **val)
{
	int	i;

	i = 0;
	if (!val || !val[i])
		return (0);
	while (val[i])
		i++;
	return (i);
}
