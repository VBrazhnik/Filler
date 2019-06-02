/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:16:33 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/18 21:20:29 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_plateau(t_plateau **plateau)
{
	int	y;

	y = 0;
	while (y < (*plateau)->height)
	{
		free((*plateau)->heat_map[y]);
		y++;
	}
	free((*plateau)->heat_map);
	free((*plateau));
	(*plateau) = NULL;
}

void	free_piece(t_piece **piece)
{
	int	y;

	y = 0;
	while (y < (*piece)->height)
	{
		free((*piece)->map[y]);
		y++;
	}
	free((*piece)->map);
	free((*piece));
	(*piece) = NULL;
}

void	reset_coords(t_filler *filler)
{
	filler->y = 0;
	filler->x = 0;
}
