/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 15:33:24 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/18 21:20:55 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft.h"
# include "get_next_line.h"

/*
** Cell Type
*/

typedef enum
{
	EMPTY = 0,
	PLAYER = -1,
	ENEMY = -2
}	t_cell_type;

/*
** Plateau
*/

/*
** height   — height of plateau
** width    — width of plateau
** heat_map — heat map of plateau which will be calculated by Manhattan distance
*/

typedef struct	s_plateau
{
	int			height;
	int			width;
	int			**heat_map;
}				t_plateau;

/*
** Piece
*/

/*
** height — height of piece
** width  — width of piece
** map    — map of piece
*/

typedef struct	s_piece
{
	int			height;
	int			width;
	char		**map;
}				t_piece;

/*
** Filler
*/

/*
** player_symbol — player symbol ['O' or 'X']
** enemy_symbol  — enemy symbol ['O' or 'X']
** plateau       — plateau information
** piece         — piece information
** y             — y coordinate on plateau where piece will be placed
** x             — x coordinate on plateau where piece will be placed
*/

typedef struct	s_filler
{
	char		player_symbol;
	char		enemy_symbol;
	t_plateau	*plateau;
	t_piece		*piece;
	int			y;
	int			x;
}				t_filler;

/*
** Functions
*/

/*
** Init
*/

t_filler		*init_filler(void);

t_plateau		*init_plateau(void);

int				**init_heat_map(int height, int width);

t_piece			*init_piece(void);

/*
** Parse
*/

int				parse_player(t_filler *filler);

int				parse_plateau_size(t_plateau *plateau);

int				parse_plateau(t_plateau *plateau, t_filler *filler);

int				parse_piece_size(t_piece *piece);

int				parse_piece(t_piece *piece);

/*
** Calculate
*/

void			calc_heat_map(t_plateau *plateau);

void			calc_coords(t_plateau *plateau,
							t_piece *piece,
							t_filler *filler);

/*
** Print
*/

void			print_coords(t_filler *filler);

/*
** Free & Reset
*/

void			free_plateau(t_plateau **plateau);

void			free_piece(t_piece **piece);

void			reset_coords(t_filler *filler);

#endif
