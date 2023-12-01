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

int	dbl_free_ptr(t_mapa *mapa1, char **ptr)
{
	free(mapa1);
	free(ptr);
	return (1);
}

int	ft_strrepeatchr(char *s, char c, int len)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(s) - 1 - len;
	while (i <= k)
	{
		if (s[i] != c)
			return (1);
		i++;
	}
	return (0);
}

char	**ft_dupchararray(char **src, char **dst, int size)
{
	int	i;

	i = 0;
	dst = (char **)malloc(sizeof(char *) * (size + 1));
	if (!dst)
		return (dst);
	while (i < size)
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst[i])
		{
			while (i >= 0)
			{
				free(dst[i]);
				i--;
			}
			free(*dst);
			return (dst);
		}
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

t_mapa	*inicializar_mapa(void)
{
	t_mapa	*mapa1;

	mapa1 = (t_mapa *)malloc(sizeof(t_mapa));
	if (!mapa1)
	{
		ft_print_error("Memory allocation for Mapa data type failed\n");
		return (mapa1);
	}
	mapa1->error = 0;
	mapa1->line = NULL;
	mapa1->map = NULL;
	mapa1->map_copy = NULL;
	mapa1->x = 0;
	mapa1->y = 0;
	mapa1->line_len = 0;
	mapa1->line_count = 0;
	mapa1->move_count = 0;
	mapa1->collective = 0;
	mapa1->collected = 0;
	mapa1->exit = 0;
	mapa1->start = 0;
	mapa1->win = 0;
	return (mapa1);
}
