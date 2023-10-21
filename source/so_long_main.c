/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:22:32 by jde-orma          #+#    #+#             */
/*   Updated: 2023/10/21 22:22:32 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_int.h"
#include "mlx.h"
#include "../libft/include/libft.h"

void	parse_file(Mapa *mapa1, char **argv)
{
	int fd;

	mapa1->line_count = ft_line_count(mapa1, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_print_error("Failed to open the text file. Check the spelling\n");
		return ;
	}
	if (!(mapa1->map = read_file_lines(fd, mapa1)))
	{
		close(fd);
		return ;
	}
	close(fd);
	if (mapa1->error > 0)
		return ;
	mapa1->map_copy = ft_dupchararray(mapa1->map, mapa1->map_copy, mapa1->line_count);
}

void	map_ini(Mapa *mapa1, int argc, char **argv)
{

	if (argument_checker(argc, argv) >= 1)
    {
        mapa1->error++;
		return ;
    }
	parse_file(mapa1, argv);
	if (!mapa1)
    {
        mapa1->error++;
		ft_printf("Mapa1 is still null...\n");
    }
	if (mapa1->error > 0)
		return ;
	if(ft_pathfinder(mapa1->map_copy, mapa1->y, mapa1->x, 
                    mapa1->line_count, (int)mapa1->line_len) == 0)
	{
		mapa1->error++;
		ft_print_error("The map cannot be solved\n");
	}
}

int	main(int argc, char **argv)
{
	Mapa 	*mapa1;

	mapa1 = inicializar_mapa();
	map_ini(mapa1, argc, argv);
	if (mapa1->error > 0)
		return 1;
	if (!mapa1)
	{
		ft_print_error("Wrong arguments");
		return (1);
	}
	ft_window(mapa1);
	mlx_hook(mapa1->window, ON_DESTROY, 1L << 5, ft_close_window, mapa1);
	mlx_hook(mapa1->window, ON_KEYDOWN, 1L << 0, ft_keyboard, mapa1);
	mlx_hook(mapa1->window, 25, 1L << 18, ft_keyboard, mapa1);
	mlx_loop(mapa1->ini);
	exit(0);
	return (0);
}
