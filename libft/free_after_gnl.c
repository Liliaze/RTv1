/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_after_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:34:20 by dboudy            #+#    #+#             */
/*   Updated: 2016/05/27 14:34:50 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_line_and_values(char *line, char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
	free(line);
}
