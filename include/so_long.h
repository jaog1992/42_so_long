/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 06:55:06 by jde-orma          #+#    #+#             */
/*   Updated: 2023/07/29 06:55:06 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct Mapa{
	int		error;
	char	*line;
	char	**map;
	char	**map_copy;
	void	*ini;
	void	*window;
	void	*file;
	void	*hook;
	int		pxl;
	int		x;
	int		y;
	size_t	line_len;
	int		line_count;
	int		move_count;
	int		collective;
	int		collected;
	int		exit;
	int		start;
	int		win;
} Mapa;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int		dbl_free_ptr(Mapa *mapa1, char **ptr);
int		ft_strrepeatchr(char *s, char c, int len);
char	**ft_dupchararray(char **src, char **dst, int size);
int		ft_pathfinder(char **ptr, int y, int x, int leny, int lenx);
int		error_check(char *line, Mapa *mapa1, int i);
int		is_valid_map(char *s, char *extension);
Mapa	*inicializar_mapa();
void	ft_put_win(Mapa *mapa1, int x, int y);
void	ft_put_wall(Mapa *mapa1, int x, int y);
void	ft_put_floor(Mapa *mapa1, int x, int y);
void	ft_put_collectives(Mapa *mapa1, int x, int y);
void	ft_put_player(Mapa *mapa1, int x, int y);
void	ft_put_exit(Mapa *mapa1, int x, int y);
void	ft_fill_floor(Mapa *mapa1);
void	ft_fill_window(Mapa *mapa1);
int		ft_close_window(Mapa *mapa1);
int		ft_keyboard(int keyhook, Mapa *mapa1);
void	ft_move_up(Mapa *mapa1);
void	ft_move_down(Mapa *mapa1);
void	ft_move_left(Mapa *mapa1);
void	ft_move_right(Mapa *mapa1);
void	ft_window(Mapa *mapa1);
int		ft_line_count(Mapa *mapa1, char *argv);
int		argument_checker(int argc, char **argv);
char	**allocate_char_array(int size);
char	**read_file_lines(int fd, Mapa *mapa1);
void	parse_file(Mapa *mapa1, char **argv);
