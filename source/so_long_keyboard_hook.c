/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:33:06 by jde-orma          #+#    #+#             */
/*   Updated: 2023/10/16 19:33:06 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "../libraries/libft/include/libft.h"

void	ft_keyboard_up(int keyhook, t_mapa *mapa1)
{
	if ((keyhook == 126 || keyhook == 13 || keyhook == 119 || keyhook == 65362)
		&& mapa1->map[mapa1->y - 1][mapa1->x] != '1'
		&& mapa1->map[mapa1->y - 1][mapa1->x] != 'E')
		ft_move_up(mapa1);
	else if ((keyhook == 126 || keyhook == 13
			|| keyhook == 119 || keyhook == 65362)
		&& mapa1->map[mapa1->y - 1][mapa1->x] == 'E'
		&& mapa1->collected == mapa1->collective)
	{
		mapa1->win = 1;
		ft_move_up(mapa1);
		ft_printf("\nYOU WIN!\n");
		ft_close_window(mapa1);
	}
}

void	ft_keyboard_left(int keyhook, t_mapa *mapa1)
{
	if ((keyhook == 123 || keyhook == 0 || keyhook == 97 || keyhook == 65361)
		&& mapa1->map[mapa1->y][mapa1->x - 1] != '1'
		&& mapa1->map[mapa1->y][mapa1->x - 1] != 'E')
		ft_move_left(mapa1);
	else if ((keyhook == 123 || keyhook == 0
			|| keyhook == 97 || keyhook == 65361)
		&& mapa1->map[mapa1->y][mapa1->x - 1] == 'E'
		&& mapa1->collected == mapa1->collective)
	{
		mapa1->win = 1;
		ft_move_left(mapa1);
		ft_printf("\nYOU WIN!\n");
		ft_close_window(mapa1);
	}
}

void	ft_keyboard_down(int keyhook, t_mapa *mapa1)
{
	if ((keyhook == 125 || keyhook == 1 || keyhook == 115 || keyhook == 65364)
		&& mapa1->map[mapa1->y + 1][mapa1->x] != '1'
		&& mapa1->map[mapa1->y + 1][mapa1->x] != 'E')
		ft_move_down(mapa1);
	else if ((keyhook == 125 || keyhook == 1 || keyhook == 115
			|| keyhook == 65364)
		&& mapa1->map[mapa1->y + 1][mapa1->x] == 'E'
		&& mapa1->collected == mapa1->collective)
	{
		mapa1->win = 1;
		ft_move_down(mapa1);
		ft_printf("\nYOU WIN!\n");
		ft_close_window(mapa1);
	}
}

void	ft_keyboard_right(int keyhook, t_mapa *mapa1)
{
	if ((keyhook == 124 || keyhook == 2 || keyhook == 100 || keyhook == 65363)
		&& mapa1->map[mapa1->y][mapa1->x + 1] != '1'
		&& mapa1->map[mapa1->y][mapa1->x + 1] != 'E')
		ft_move_right(mapa1);
	else if ((keyhook == 124 || keyhook == 2
			|| keyhook == 100 || keyhook == 65363)
		&& mapa1->map[mapa1->y][mapa1->x + 1] == 'E'
		&& mapa1->collected == mapa1->collective)
	{
		mapa1->win = 1;
		ft_move_right(mapa1);
		ft_printf("\nYOU WIN!\n");
		ft_close_window(mapa1);
	}
}

int	ft_keyboard(int keyhook, t_mapa *mapa1)
{
	if (keyhook == 12 || keyhook == 53 || keyhook == 113 || keyhook == 65307)
		ft_close_window(mapa1);
	ft_keyboard_up(keyhook, mapa1);
	ft_keyboard_down(keyhook, mapa1);
	ft_keyboard_left(keyhook, mapa1);
	ft_keyboard_right(keyhook, mapa1);
	return (0);
}
