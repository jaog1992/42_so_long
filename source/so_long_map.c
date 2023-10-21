/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:19:22 by jde-orma          #+#    #+#             */
/*   Updated: 2023/08/07 18:19:22 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_int.h"
#include "mlx.h"
#include "../libft/include/libft.h"

int	ft_line_count(Mapa *mapa1, char *argv)
{
	char	*line = NULL;
	int		fd;

	fd = open(argv, O_RDONLY);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (line)
			mapa1->line_count++;
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (mapa1->line_count);
}

int	argument_checker(int argc, char **argv)
{
	if (argc == 1)
		return (ft_print_error("Please, insert one argument...\n"));
	if (argc > 2)
		ft_print_error("Too many arguments. First will be taken.\n");
	return (is_valid_map(argv[1], ".ber"));
}

char	**allocate_char_array(int size)
{
	char	**ptr;
	int		i;

	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ptr)
	{
	i = 0;
    while (i < size)
    {
        free(ptr[i]);
        i++;
    }
    free(ptr);
	}
	return (ptr);
}

char	**read_file_lines(int fd, Mapa *mapa1)
{
	char	**ptr;
	int		i;

	ptr = allocate_char_array(mapa1->line_count);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < mapa1->line_count)
	{
		mapa1->line = ft_get_next_line(fd);
		if (!mapa1->line)
			break;
		ptr[i] = ft_strdup(mapa1->line);
		i++;
	}
	i = 0;
	while (i < mapa1->line_count)
	{
		mapa1->error += error_check(ptr[i], mapa1, i);
		if (mapa1->error > 0)
			return (NULL);
		i++;
	}
	return (ptr);
}
