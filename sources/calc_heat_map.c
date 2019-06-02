/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_heat_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:53:20 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/11 16:53:20 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	calc_manhattan_dist(t_plateau *plateau, int x, int y)
{
	int	j;
	int	i;
	int	dist;
	int	min_dist;

	min_dist = FT_INT_MAX;
	j = 0;
	while (j < plateau->height)
	{
		i = 0;
		while (i < plateau->width)
		{
			if (plateau->heat_map[j][i] == ENEMY)
			{
				dist = FT_ABS(i - x) + FT_ABS(j - y);
				if (dist < min_dist)
					min_dist = dist;
			}
			i++;
		}
		j++;
	}
	return (min_dist);
}

void		calc_heat_map(t_plateau *plateau)
{
	int	x;
	int	y;

	y = 0;
	while (y < plateau->height)
	{
		x = 0;
		while (x < plateau->width)
		{
			if (plateau->heat_map[y][x] == EMPTY)
				plateau->heat_map[y][x] = calc_manhattan_dist(plateau, x, y);
			x++;
		}
		y++;
	}
}
