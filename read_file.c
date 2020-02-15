/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <tnichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:05:25 by gusujio           #+#    #+#             */
/*   Updated: 2020/02/15 22:28:48 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned long long int	ft_degree(unsigned
						long long int x, unsigned long long int n)
{
	if (n == 0)
		return (1);
	else if (n == 1)
		return (x);
	else if (n % 2 == 0)
		return (ft_degree(x * x, n / 2));
	else
		return (ft_degree(x * x, n / 2) * x);
}

void					stop(char *s2, t_ili *z_line)
{
	int					i;

	i = 2;
	s2++;
	if (*s2 != '0' && *(s2 + 1) != 'x' && *(s2 + 9) != 0)
		error();
	while (s2[i])
	{
		if (!((s2[i] >= 'A' && s2[i] <= 'F') || ft_isdigit(s2[i])))
			error();
		i++;
	}
	z_line->color = perevod(s2 + 2);
}

void					fill_matrix(
							t_ili *z_line,
							char *line,
							t_fdf **data, int len)
{
	char				**nums;
	int					i;
	char				*s2;

	nums = ft_strsplit(line, ' ');
	i = -1;
	while (nums[++i])
	{
		if ((s2 = ft_strchr(nums[i], ',')))
			stop(s2, z_line + i);
		else
		{
			if (!ft_isnumber(nums[i]))
				error();
			z_line[i].color = 0;
		}
		z_line[i].number = ft_atoi(nums[i]);
		if (z_line[i].number > (*data)->max)
			(*data)->max = z_line[i].number;
		if (z_line[i].number < (*data)->min)
			(*data)->min = z_line[i].number;
		free(nums[i]);
	}
	free(nums);
	sravn(i, len);
}

void					read_file_3(char *file_name, t_fdf **data, int *i)
{
	(*data)->height = get_height(file_name);
	(*data)->width = get_width(file_name);
	(*data)->z_matrix = (t_ili **)malloc(sizeof(t_ili *)
			* ((*data)->height));
	*i = 0;
	while (*i <= (*data)->height)
		(*data)->z_matrix[(*i)++] = (t_ili *)malloc(sizeof(t_ili)
				* ((*data)->width));
}

void					read_file(char *file_name, t_fdf **data)
{
	int					fd;
	char				*line;
	int					i;
	int					len;

	read_file_3(file_name, data, &i);
	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		error();
	i = 0;
	(*data)->max = -2147483648;
	(*data)->min = +2147483647;
	while (get_next_line(fd, &line))
	{
		if (i == 0)
			len = validlen(line);
		fill_matrix((*data)->z_matrix[i], line, data, len);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}
