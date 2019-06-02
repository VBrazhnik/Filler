/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:04:36 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/18 21:23:25 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	*filler;

	if (!(filler = init_filler())
		|| parse_player(filler) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	while ((filler->plateau = init_plateau())
		&& parse_plateau_size(filler->plateau) == EXIT_SUCCESS
		&& (filler->plateau->heat_map = init_heat_map(
				filler->plateau->height, filler->plateau->width))
		&& parse_plateau(filler->plateau, filler) == EXIT_SUCCESS
		&& (filler->piece = init_piece())
		&& parse_piece_size(filler->piece) == EXIT_SUCCESS
		&& parse_piece(filler->piece) == EXIT_SUCCESS)
	{
		calc_heat_map(filler->plateau);
		calc_coords(filler->plateau, filler->piece, filler);
		print_coords(filler);
		free_plateau(&(filler->plateau));
		free_piece(&(filler->piece));
		reset_coords(filler);
	}
	return (EXIT_FAILURE);
}
