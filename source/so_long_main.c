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
#include "mlx.h"
#include "../libraries/libft/include/libft.h"

int	error_check(char *line, t_mapa *mapa1, int i)
{
	if (i == 0)
		return (first_line_error_check(line, mapa1, 0));
	else if (i == (mapa1->line_count - 1))
		return (last_line_error_check(line, mapa1, 0));
	else
		return (middle_line_error_check(line, mapa1, i));
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

void	parse_file(t_mapa *mapa1, char **argv)
{
	int	fd;

	mapa1->line_count = ft_line_count(mapa1, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_print_error("Failed to open the text file. Check the spelling\n");
		return ;
	}
	mapa1->map = read_file_lines(fd, mapa1);
	if (!mapa1->map)
	{
		close(fd);
		return ;
	}
	close(fd);
	if (mapa1->error > 0)
		return ;
	mapa1->map_copy = ft_dupchararray(mapa1->map, mapa1->map_copy,
			mapa1->line_count);
}

void	map_ini(t_mapa *mapa1, int argc, char **argv)
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
		ft_print_error("Map parsing returned null\n");
	}
	if (mapa1->error > 0)
		return ;
	if (!mapa1->map_copy)
		ft_print_error("Map handling returned null\n");
	if (ft_pathfinder(mapa1->map_copy, mapa1->y, mapa1->x, mapa1) == 0)
	{
		mapa1->error++;
		ft_print_error("The map cannot be solved\n");
	}
	mapa1->collected = 0;
}

int	main(int argc, char **argv)
{
	t_mapa	*mapa1;

	mapa1 = inicializar_mapa();
	map_ini(mapa1, argc, argv);
	if (mapa1->error > 0)
	{
		exit (1);
		system("leaks so_long");
		return (EXIT_FAILURE);
	}
	if (!mapa1)
	{
		ft_print_error("Wrong arguments");
		return (EXIT_FAILURE);
	}
	mapa1->pwd = ft_locate(argv[0]);
	//ft_printf("El string es %s\n", mapa1->pwd);
	//ft_printf("La textura está en %s\n", ft_strjoin(mapa1->pwd, "../../assets/textures/wall.xpm"));
	ft_window(mapa1);
	mlx_hook(mapa1->window, ON_DESTROY, 1L << 5, ft_close_window, mapa1);
	mlx_hook(mapa1->window, ON_KEYDOWN, 1L << 0, ft_keyboard, mapa1);
	mlx_hook(mapa1->window, 25, 1L << 18, ft_keyboard, mapa1);
	mlx_loop(mapa1->ini);
	exit(0);
	system("leaks so_long");
	return (EXIT_SUCCESS);
}
