/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:56:14 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/04/29 14:41:29 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	validate_piece(t_piece *piece)
{
	int	x;
	int	y;

	y = 0;
	while (y < piece->height)
	{
		x = 0;
		while (x < piece->width)
		{
			if (piece->map[y][x] != '*' && piece->map[y][x] != '.')
				return (EXIT_FAILURE);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int			parse_piece(t_piece *piece)
{
	int	y;

	y = 0;
	if (!(piece->map = (char **)ft_memalloc(sizeof(char *) * piece->height)))
		return (EXIT_FAILURE);
	while (y < piece->height)
	{
		if (get_next_line(0, &(piece->map[y])) != 1
			|| (int)ft_strlen(piece->map[y]) != piece->width)
			return (EXIT_FAILURE);
		y++;
	}
	return (validate_piece(piece));
}
