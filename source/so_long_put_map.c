/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_put_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:34:02 by jde-orma          #+#    #+#             */
/*   Updated: 2023/10/16 19:34:02 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "../libraries/libft/include/libft.h"

void	ft_fill_floor(t_mapa *mapa1)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapa1->line_count)
	{
		x = 0;
		while (x < (int)mapa1->line_len)
		{
			mapa1->file = mlx_xpm_file_to_image(mapa1->ini,
					"./assets/textures/floor.xpm", &mapa1->pxl, &mapa1->pxl);
			if (!mapa1->file)
				ft_print_error("!mapa1->file\n");
			mlx_put_image_to_window(mapa1->ini, mapa1->window,
				mapa1->file, mapa1->pxl * x, mapa1->pxl * y);
			x++;
		}
		y++;
	}
}

void	ft_fill_window(t_mapa *mapa1)
{
	int	y;
	int	x;

	ft_fill_floor(mapa1);
	y = 0;
	while (y < mapa1->line_count)
	{
		x = 0;
		while (x < (int)mapa1->line_len)
		{
			if (mapa1->map[y][x] == '1')
				ft_put_wall(mapa1, x, y);
			if (mapa1->map[y][x] == 'C')
				ft_put_collectives(mapa1, x, y);
			if (mapa1->map[y][x] == 'P')
				ft_put_player(mapa1, x, y);
			if (mapa1->map[y][x] == 'E')
				ft_put_exit(mapa1, x, y);
			x++;
		}
		y++;
	}
}

void	ft_window(t_mapa *mapa1)
{
	mapa1->pxl = 64;
	mapa1->ini = mlx_init();
	if (!mapa1->ini)
	{
		ft_print_error("MLX init returns NULL\n");
		free(mapa1->ini);
		return ;
	}
	mapa1->window = mlx_new_window(mapa1->ini,
			mapa1->pxl * (int)mapa1->line_len,
			mapa1->pxl * (int)mapa1->line_count, "jde-orma");
	ft_fill_window(mapa1);
}

int	ft_close_window(t_mapa *mapa1)
{
	mlx_destroy_window(mapa1->ini, mapa1->window);
	exit(1);
	return (0);
}
