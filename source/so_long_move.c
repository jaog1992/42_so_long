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
#include "mlx_int.h"
#include "mlx.h"
#include "../libft/include/libft.h"

void	ft_move_up(Mapa *mapa1)
{
	if(mapa1->map[mapa1->y - 1][mapa1->x] == 'C')
		mapa1->collected++;
	mapa1->map[mapa1->y][mapa1->x] = '0';
	mapa1->map[mapa1->y - 1][mapa1->x] = 'P';
	mapa1->move_count++;
	ft_put_floor(mapa1, mapa1->x, mapa1->y);
	ft_put_player(mapa1, mapa1->x, mapa1->y - 1);
	mapa1->y--;
	printf("Movements: %d\n", mapa1->move_count);
}

void	ft_move_down(Mapa *mapa1)
{
	if(mapa1->map[mapa1->y + 1][mapa1->x] == 'C')
		mapa1->collected++;
	mapa1->map[mapa1->y][mapa1->x] = '0';
	mapa1->map[mapa1->y + 1][mapa1->x] = 'P';
	ft_put_floor(mapa1, mapa1->x, mapa1->y);
	ft_put_player(mapa1, mapa1->x, mapa1->y + 1);
	mapa1->move_count++;
	mapa1->y++;
	printf("Movements: %d\n", mapa1->move_count);
}

void	ft_move_left(Mapa *mapa1)
{
	if(mapa1->map[mapa1->y][mapa1->x - 1] == 'C')
		mapa1->collected++;
	mapa1->map[mapa1->y][mapa1->x] = '0';
	mapa1->map[mapa1->y][mapa1->x - 1] = 'P';
	ft_put_floor(mapa1, mapa1->x, mapa1->y);
	ft_put_player(mapa1, mapa1->x - 1, mapa1->y);
	mapa1->move_count++;
	mapa1->x--;
	printf("Movements: %d\n", mapa1->move_count);
}

void	ft_move_right(Mapa *mapa1)
{
	if(mapa1->map[mapa1->y][mapa1->x + 1] == 'C')
		mapa1->collected++;
	mapa1->map[mapa1->y][mapa1->x] = '0';
	mapa1->map[mapa1->y][mapa1->x + 1] = 'P';
	ft_put_floor(mapa1, mapa1->x, mapa1->y);
	ft_put_player(mapa1, mapa1->x + 1, mapa1->y);
	mapa1->move_count++;
	mapa1->x++;
	printf("Movements: %d\n", mapa1->move_count);
}
