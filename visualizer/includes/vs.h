/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:56:32 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/06/02 16:30:10 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VS_H

# define VS_H

# include "libft.h"
# include "get_next_line.h"
# include <SDL2/SDL.h>

# define HEIGHT			1000
# define WIDTH			1000

/*
** Plateau
*/

/*
** height   — height of plateau
** width    — width of plateau
** map      — map of plateau
** next     — next plateau
** previous — previous plateau
*/

typedef struct			s_plateau
{
	int					height;
	int					width;
	char				**map;
	struct s_plateau	*next;
	struct s_plateau	*previous;
}						t_plateau;

/*
** Visualizer
*/

/*
** window      — window of visualizer
** surface     — surface for drawing
** plateau     — list of plateaus
** y           — y coordinate on surface of window for plateau drawing
** x           — x coordinate on surface of window for plateau drawing
** cell_shift  — distance between cells
** cell_length — length (height/width) of cell to draw
** p1_counter  — number of cells that were filled with player #1
** p2_counter  — number of cells that were filled with player #2
** close       — flag of window displaying
** pause       — flag of pause
*/

typedef struct			s_vs
{
	SDL_Window			*window;
	SDL_Surface			*surface;
	t_plateau			*plateau;
	int					y;
	int					x;
	int					cell_shift;
	int					cell_length;
	int					p1_counter;
	int					p2_counter;
	t_bool				close;
	t_bool				pause;
}						t_vs;

/*
** Functions
*/

/*
** Init
*/

t_vs					*init_vs(void);

t_plateau				*init_plateau(void);

SDL_Color				init_color(int red, int green, int blue, int alpha);

/*
** Parse
*/

void					parse(t_vs *vs);

/*
** Plateau
*/

void					add_plateau(t_vs *vs, t_plateau *plateau);

/*
** Color
*/

SDL_Color				get_color(char symbol);

/*
** Calculate & Count
*/

void					calc_dimensions(t_vs *vs, t_plateau *plateau);

void					count_players(t_vs *vs, t_plateau *plateau);

/*
** Draw
*/

void					draw_background(t_vs *vs);

void					draw_status(t_vs *vs);

void					draw_plateau(t_vs *vs);

/*
** Event
*/

void					check_event(t_vs *vs);

/*
** Print
*/

void					print_usage(void);

/*
** Utils
*/

void					close(t_vs *vs);

void					terminate(const char *s);

#endif
