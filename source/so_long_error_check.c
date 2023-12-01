/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:09:18 by jde-orma          #+#    #+#             */
/*   Updated: 2023/07/31 13:09:18 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libraries/libft/include/libft.h"

int	ft_invalid_char(char *s, t_mapa *mapa1, int len, int line_number)
{
	int	c;

	c = 0;
	while (c < len)
	{
		if (!(s[c] == '1' || s[c] == '0' || s[c] == 'C' || s[c] == 'E' || \
			s[c] == 'P'))
			mapa1->error += ft_print_error("Found char != from '10CEP'\n");
		if (s[c] == 'E')
			mapa1->exit++;
		if (s[c] == 'P')
		{
			mapa1->start++;
			mapa1->x = c;
			mapa1->y = line_number;
		}
		if (s[c] == 'C')
			mapa1->collective++;
		c++;
	}
	return (0);
}

int	first_line_error_check(char *line, t_mapa *mapa1, int error)
{
	error += ft_strrepeatchr(line, '1', 1);
	if (error == 1)
	{
		mapa1->error += ft_print_error("Not all 1st line chars == to 1\n");
		ft_print_red(line);
	}
	mapa1->line_len = ft_strlen(line) - 1;
	return (0);
}

void	ft_character_count(t_mapa *mapa1)
{
	if (mapa1->start > 1 || mapa1->start <= 0)
	{
		mapa1->error += ft_print_error("Nº of 'Start'-s must be == 1, not ");
		ft_print_red(ft_itoa(mapa1->start));
		return ;
	}
	if (mapa1->collective < 1)
	{
		mapa1->error += ft_print_error(">=1 collectives expected, not ");
		ft_print_red(ft_itoa(mapa1->collective));
		return ;
	}
	if (mapa1->exit > 1 || mapa1->exit <= 0)
	{
		mapa1->error += ft_print_error("Nº of 'Exits' must be == 1, not ");
		ft_print_red(ft_itoa(mapa1->exit));
		return ;
	}
	return ;
}

int	last_line_error_check(char *line, t_mapa *mapa1, int error)
{
	error += ft_strrepeatchr(line, '1', 0);
	if (error == 1)
	{
		mapa1->error += ft_print_error("Char != 1 in last line\n");
		ft_print_red(line);
		return (1);
	}
	if (mapa1->line_len != ((size_t)ft_strlen(line)))
	{
		mapa1->error += ft_print_error("Last line with wrong length -> ");
		ft_printf("%s != ", ft_itoa((int)mapa1->line_len));
		ft_print_red(ft_itoa((int)ft_strlen(line)));
		return (1);
	}
	ft_character_count(mapa1);
	if (mapa1->error > 0)
		return (1);
	return (ft_strrepeatchr(line, '1', 0));
}

int	middle_line_error_check(char *line, t_mapa *mapa1, int line_number)
{
	if (mapa1->line_len != ((size_t)ft_strlen(line) - 1))
	{
		mapa1->error += ft_print_error("Line with wrong length -> ");
		ft_printf("%s != ", ft_itoa((int)mapa1->line_len));
		ft_print_red(ft_itoa((int)ft_strlen(line) - 1));
		return (1);
	}
	if (line[0] != '1' || line[mapa1->line_len - 1] != '1')
	{
		mapa1->error += ft_print_error("Line start/end != '1'\n");
		ft_printf("%s\n", line);
		return (1);
	}
	return (ft_invalid_char(line, mapa1, (ft_strlen(line) - 2), line_number));
}
