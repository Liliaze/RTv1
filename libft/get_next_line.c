/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 12:40:08 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/03 15:28:52 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	check_n(char **buf, char **line)
{
	char	*n;
	char	*new_buf;

	n = NULL;
	new_buf = NULL;
	if (*buf)
	{
		if ((n = ft_strchr(*buf, '\n')))
		{
			*n = '\0';
			*line = ft_strdup(*buf);
			if (*(n + 1))
			{
				new_buf = ft_strdup(n + 1);
				free(*buf);
				*buf = new_buf;
			}
			else
				ft_strdel(buf);
			return (1);
		}
	}
	return (0);
}

static int	read_buff_size(int fd, char **buf, int *nb_c)
{
	char	*tmp;
	char	*new_buf;
	int		len;

	len = 0;
	tmp = NULL;
	new_buf = NULL;
	if ((tmp = (char *)malloc(sizeof(char *) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	if ((*nb_c = read(fd, tmp, BUFF_SIZE)) == -1)
		return (-1);
	tmp[*nb_c] = '\0';
	if (*buf && *nb_c)
	{
		new_buf = ft_strjoin(*buf, tmp);
		free(*buf);
		ft_strdel(&tmp);
		*buf = new_buf;
	}
	else if (*nb_c)
		*buf = tmp;
	else
		ft_strdel(&tmp);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*tab[257] = {0};
	int			nb_c;
	int			n;

	nb_c = 1;
	n = 0;
	if (fd < 0 || fd > 256)
		return (-1);
	while (!(n = check_n(&tab[fd], line)) && nb_c)
	{
		if ((read_buff_size(fd, &tab[fd], &nb_c)) == -1)
			return (-1);
	}
	if (n == 1)
		return (1);
	else if (!n && !nb_c && tab[fd])
	{
		if ((*line = ft_strdup(tab[fd])) == NULL)
			return (-1);
		ft_strdel(&tab[fd]);
		return (1);
	}
	return (0);
}
