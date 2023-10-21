/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_put_xpm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:53:01 by jde-orma          #+#    #+#             */
/*   Updated: 2023/10/21 21:53:01 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_int.h"
#include "mlx.h"
#include "../libft/include/libft.h"

void	ft_put_wall(Mapa *mapa1, int x, int y)
{
	mapa1->file = mlx_xpm_file_to_image(mapa1->ini,
			"./assets/wall.xpm", &mapa1->pxl, &mapa1->pxl);
	mlx_put_image_to_window (mapa1->ini, mapa1->window,
		mapa1->file, mapa1->pxl * x, mapa1->pxl * y);

}

void	ft_put_floor(Mapa *mapa1, int x, int y)
{
	mapa1->file = mlx_xpm_file_to_image(mapa1->ini,
			"./assets/floor.xpm", &mapa1->pxl, &mapa1->pxl);
	mlx_put_image_to_window (mapa1->ini, mapa1->window,
		mapa1->file, mapa1->pxl * x, mapa1->pxl * y);
}

void	ft_put_collectives(Mapa *mapa1, int x, int y)
{
	mapa1->file = mlx_xpm_file_to_image(mapa1->ini,
			"./assets/collective.xpm", &mapa1->pxl, &mapa1->pxl);
	mlx_put_image_to_window (mapa1->ini, mapa1->window,
		mapa1->file, mapa1->pxl * x, mapa1->pxl * y);
}

void	ft_put_player(Mapa *mapa1, int x, int y)
{
	if(mapa1->win == 1)
	{
		mapa1->file = mlx_xpm_file_to_image(mapa1->ini,
			"./assets/win.xpm", &mapa1->pxl, &mapa1->pxl);
	}
	else
	{
		mapa1->file = mlx_xpm_file_to_image(mapa1->ini,
			"./assets/stopped.xpm", &mapa1->pxl, &mapa1->pxl);
	}
	mlx_put_image_to_window (mapa1->ini, mapa1->window,
		mapa1->file, mapa1->pxl * x, mapa1->pxl * y);
}

void	ft_put_exit(Mapa *mapa1, int x, int y)
{
	mapa1->file = mlx_xpm_file_to_image(mapa1->ini,
				"./assets/door.xpm", &mapa1->pxl, &mapa1->pxl);
	mlx_put_image_to_window (mapa1->ini, mapa1->window,
		mapa1->file, mapa1->pxl * x,
		mapa1->pxl * y);
}
