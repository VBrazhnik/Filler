/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:15:25 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/12 14:47:26 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void	calc_dimensions(t_vs *vs, t_plateau *plateau)
{
	int	plateau_height;
	int	plateau_width;

	if (plateau->height > plateau->width)
		vs->cell_shift = (HEIGHT * 90 / 100) / plateau->height;
	else
		vs->cell_shift = (WIDTH * 90 / 100) / plateau->width;
	plateau_height = vs->cell_shift * vs->plateau->height;
	plateau_width = vs->cell_shift * vs->plateau->width;
	vs->cell_length = vs->cell_shift * 85 / 100;
	vs->y = (HEIGHT - plateau_height + (vs->cell_shift - vs->cell_length)) / 2;
	vs->x = (WIDTH - plateau_width + (vs->cell_shift - vs->cell_length)) / 2;
}

void	count_players(t_vs *vs, t_plateau *plateau)
{
	int	y;
	int	x;

	vs->p1_counter = 0;
	vs->p2_counter = 0;
	y = 0;
	while (y < plateau->height)
	{
		x = 0;
		while (x < plateau->width)
		{
			if (ft_toupper(plateau->map[y][x]) == 'O')
				vs->p1_counter++;
			else if (ft_toupper(plateau->map[y][x]) == 'X')
				vs->p2_counter++;
			x++;
		}
		y++;
	}
}
