/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:58:21 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/04 17:48:11 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	parse_plateau_line(char *plateau_line,
								int *heat_map_line,
								t_plateau *plateau,
								t_filler *filler)
{
	int	x;

	x = 0;
	while (x < plateau->width)
	{
		if (plateau_line[x] == '.')
			heat_map_line[x] = EMPTY;
		else if (ft_toupper(plateau_line[x]) == filler->player_symbol)
			heat_map_line[x] = PLAYER;
		else if (ft_toupper(plateau_line[x]) == filler->enemy_symbol)
			heat_map_line[x] = ENEMY;
		else
			return (EXIT_FAILURE);
		x++;
	}
	return (EXIT_SUCCESS);
}

int			parse_plateau(t_plateau *plateau, t_filler *filler)
{
	int		y;
	char	*line;

	if (get_next_line(0, &line) != 1
		|| (int)ft_strlen(line) != plateau->width + 4)
	{
		ft_strdel(&line);
		return (EXIT_FAILURE);
	}
	ft_strdel(&line);
	y = 0;
	while (y < plateau->height)
	{
		if (get_next_line(0, &line) != 1
			|| (int)ft_strlen(line) != plateau->width + 4
			|| parse_plateau_line(&line[4],
					plateau->heat_map[y], plateau, filler) != EXIT_SUCCESS)
		{
			ft_strdel(&line);
			return (EXIT_FAILURE);
		}
		ft_strdel(&line);
		y++;
	}
	return (EXIT_SUCCESS);
}
