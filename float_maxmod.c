/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_maxmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <tnichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:05:05 by tnichell          #+#    #+#             */
/*   Updated: 2020/02/15 22:38:03 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		float_mod(float f)
{
	return ((f < 0) ? -f : f);
}

float		float_max(float f1, float f2)
{
	return ((f1 > f2) ? f1 : f2);
}

void		sravn(int i, int len)
{
	if (i != len)
		error();
}

int			validlen(char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
	return (i);
}

int			ft_isnumber(const char *s)
{
	int					i;
	int					l;

	l = ft_strlen(s);
	if (((s[0] != '-' && ft_strcmp(s, "2147483647") > 0) && l == 10) || l > 10)
		return (0);
	if ((s[0] == '-' && ft_strcmp(s + 1, "2147483648") > 0
		&& l == 11) || l > 11)
		return (0);
	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
