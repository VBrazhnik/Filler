/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:31:06 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/11 16:26:14 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*init_filler(void)
{
	t_filler	*filler;

	if ((filler = (t_filler *)ft_memalloc(sizeof(t_filler))))
	{
		filler->player_symbol = 0;
		filler->enemy_symbol = 0;
		filler->plateau = NULL;
		filler->piece = NULL;
	}
	return (filler);
}

t_plateau	*init_plateau(void)
{
	t_plateau	*plateau;

	if ((plateau = (t_plateau *)ft_memalloc(sizeof(t_plateau))))
	{
		plateau->height = 0;
		plateau->width = 0;
		plateau->heat_map = NULL;
	}
	return (plateau);
}

int			**init_heat_map(int height, int width)
{
	int	**heat_map;
	int	y;

	y = 0;
	if ((heat_map = (int **)ft_memalloc(sizeof(int *) * height)))
	{
		while (y < height)
		{
			if (!(heat_map[y] = (int *)ft_memalloc(sizeof(int) * width)))
			{
				while (--y >= 0)
					free(heat_map[y]);
				free(heat_map);
				return (NULL);
			}
			y++;
		}
	}
	return (heat_map);
}

t_piece		*init_piece(void)
{
	t_piece	*piece;

	if ((piece = (t_piece *)ft_memalloc(sizeof(t_piece))))
	{
		piece->height = 0;
		piece->width = 0;
		piece->map = NULL;
	}
	return (piece);
}
