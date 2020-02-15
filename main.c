/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <tnichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:56:52 by gusujio           #+#    #+#             */
/*   Updated: 2020/02/15 23:37:15 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_key2(int key, t_fdf *data)
{
	if (key == 53)
		exit(0);
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 7)
		data->tettax += 0.1;
	if (key == 8)
		data->tettay += 0.1;
	if (key == 9)
		data->tettaz += 0.1;
}

int		deal_key(int key, t_fdf *data)
{
	deal_key2(key, data);
	if (key == 13)
		data->zoomz *= 1.2;
	if (key == 1)
		data->zoomz /= 1.2;
	if (key == 24)
		data->zoom *= 1.2;
	if (key == 27)
		data->zoom /= 1.2;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		hook_wndexit(void)
{
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2)
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		read_file(argv[1], &data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
		data->zoom = 20;
		data->shift_x = 0;
		data->shift_y = 0;
		data->tettax = 0;
		data->tettay = 0;
		data->tettaz = 0;
		data->zoomz = 10;
		draw(data);
		mlx_hook(data->win_ptr, 2, 0, deal_key, data);
		mlx_hook(data->win_ptr, 17, 0, hook_wndexit, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		error();
	return (0);
}
