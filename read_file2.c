/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <tnichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:15:16 by gusujio           #+#    #+#             */
/*   Updated: 2020/02/15 22:31:28 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

int			perevod(char *s)
{
	int i;
	int m;
	int l;
	int b;

	i = 0;
	l = strlen(s);
	m = 0;
	while (s[i])
	{
		b = s[i] > 64 ? s[i] - 55 : s[i] - 48;
		m += b * ft_degree(16, --l);
		i++;
	}
	return (m);
}

int			get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;
	int		g;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		error();
	height = 0;
	while ((g = get_next_line(fd, &line)) > 0)
	{
		height++;
		free(line);
	}
	free(line);
	if (g < 0)
		error();
	close(fd);
	return (height);
}

int			get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = wordcount(line, ' ');
	free(line);
	return (width);
}
