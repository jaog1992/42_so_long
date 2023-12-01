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

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"

typedef struct s_mapa{
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
	char	direction;
	char	*pwd;
}	t_mapa;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int		dbl_free_ptr(t_mapa *mapa1, char **ptr);
int		ft_strrepeatchr(char *s, char c, int len);
char	**ft_dupchararray(char **src, char **dst, int size);
int		ft_pathfinder(char **ptr, int y, int x, t_mapa *m);
int		error_check(char *line, t_mapa *mapa1, int i);
int		first_line_error_check(char *line, t_mapa *mapa1, int error);
int		last_line_error_check(char *line, t_mapa *mapa1, int error);
int		middle_line_error_check(char *line, t_mapa *mapa1, int line_number);
int		is_valid_map(char *s, char *extension);
t_mapa	*inicializar_mapa(void);
void	ft_put_win(t_mapa *mapa1, int x, int y);
void	ft_put_wall(t_mapa *mapa1, int x, int y);
void	ft_put_floor(t_mapa *mapa1, int x, int y);
void	ft_put_collectives(t_mapa *mapa1, int x, int y);
void	ft_put_player(t_mapa *mapa1, int x, int y);
void	ft_put_exit(t_mapa *mapa1, int x, int y);
void	ft_fill_floor(t_mapa *mapa1);
void	ft_fill_window(t_mapa *mapa1);
int		ft_close_window(t_mapa *mapa1);
int		ft_keyboard(int keyhook, t_mapa *mapa1);
void	ft_move_up(t_mapa *mapa1);
void	ft_move_down(t_mapa *mapa1);
void	ft_move_left(t_mapa *mapa1);
void	ft_move_right(t_mapa *mapa1);
void	ft_window(t_mapa *mapa1);
int		ft_line_count(t_mapa *mapa1, char *argv);
int		argument_checker(int argc, char **argv);
char	**allocate_char_array(int size);
char	**read_file_lines(int fd, t_mapa *mapa1);
void	parse_file(t_mapa *mapa1, char **argv);
char	*ft_locate(char *str);
#endif
