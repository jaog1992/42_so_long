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
#include "../libft/include/libft.h"

int	ft_pathfinder(char **ptr, int y, int x, int leny, int lenx)
{
	if (y < 0 || y >= leny || x < 0 || x >= lenx)
		return (0);
	if (ptr[y][x] == 'E')
		return (1);
	if (ptr[y][x] == 'P')
		ptr[y][x] = '0';
	if (ptr[y][x] == '0' || ptr[y][x] == 'C')
	{
		ptr[y][x] = '1';
		if (ft_pathfinder(ptr, y - 1, x, leny, lenx) ||
			ft_pathfinder(ptr, y + 1, x, leny, lenx) ||
			ft_pathfinder(ptr, y, x - 1, leny, lenx) ||
			ft_pathfinder(ptr, y, x + 1, leny, lenx))
		{
			return (1);
		}
		ptr[y][x] = '0';
	}
	return (0);
}