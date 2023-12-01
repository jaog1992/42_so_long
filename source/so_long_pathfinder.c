/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 06:55:06 by jde-orma          #+#    #+#             */
/*   Updated: 2023/07/29 06:55:06 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libraries/libft/include/libft.h"

int	ft_pathfinder(char **ptr, int y, int x, t_mapa *mapa)
{
	if (y < 0 || y >= mapa->line_count || x < 0 || x >= (int)mapa->line_len)
		return (0);
	if (mapa->collected == (mapa->collective + 1))
		return (1);
	if (ptr[y][x] == 'C' || ptr[y][x] == 'E')
		mapa->collected++;
	if (ptr[y][x] == 'C' || ptr[y][x] == 'P')
		ptr[y][x] = '0';
	if (ptr[y][x] == 'E')
		ptr[y][x] = '1';
	if (ptr[y][x] == '0')
	{
		ptr[y][x] = '1';
		if (ft_pathfinder(ptr, y - 1, x, mapa)
			|| ft_pathfinder(ptr, y + 1, x, mapa)
			|| ft_pathfinder(ptr, y, x - 1, mapa)
			|| ft_pathfinder(ptr, y, x + 1, mapa))
			return (1);
		ptr[y][x] = '0';
	}
	return (0);
}
