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

int	dbl_free_ptr(Mapa *mapa1, char **ptr)
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

char **ft_dupchararray(char **src, char **dst, int size)
{
    int i;

	i = 0;
    if (dst)
	{
        while (dst[i]) 
		{
            free(dst[i]);
            i++;
        }
        free(*dst);
    }
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

int	is_valid_map(char *s, char *extension)
{
	int	i;

	i = 0;
	while ((s[i + (ft_strlen(s) - 4)] != '\0') && i < 4)
	{
		if (extension[i] != s[i + (ft_strlen(s) - 4)])
		{
			ft_print_error("File extension is not valid\n");
			return (1);
		}
		i++;
	}
	return (0);
}

Mapa *inicializar_mapa()
{
	Mapa *mapa1;

	mapa1 = (Mapa *)malloc(sizeof(Mapa));
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
	mapa1->exit = 0;
	mapa1->start = 0;
	mapa1->win = 0;
	return (mapa1);
}
