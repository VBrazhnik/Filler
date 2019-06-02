/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:13:42 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/11 21:39:01 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

static void	draw_rect(t_vs *vs, SDL_Rect *rect, SDL_Color color)
{
	if (SDL_FillRect(vs->surface, rect,
			SDL_MapRGB(vs->surface->format, color.r, color.g, color.b)) < 0)
		terminate(SDL_GetError());
}

void		draw_background(t_vs *vs)
{
	SDL_Color	white;

	white = init_color(255, 255, 255, 255);
	draw_rect(vs, NULL, white);
}

void		draw_status(t_vs *vs)
{
	SDL_Rect	rect;
	SDL_Color	red;
	SDL_Color	blue;

	red = init_color(200, 53, 48, 255);
	blue = init_color(78, 150, 207, 255);
	rect = (SDL_Rect){ 0, 0, WIDTH, 10 };
	draw_rect(vs, &rect, blue);
	rect.w = WIDTH * vs->p1_counter / (vs->p1_counter + vs->p2_counter);
	draw_rect(vs, &rect, red);
	rect = (SDL_Rect){ 0, HEIGHT - 10, WIDTH, 10 };
	if (vs->p1_counter > vs->p2_counter)
		draw_rect(vs, &rect, red);
	else if (vs->p2_counter > vs->p1_counter)
		draw_rect(vs, &rect, blue);
}

static void	draw_cell(t_vs *vs, int x, int y, SDL_Color color)
{
	SDL_Rect	rect;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		rect = (SDL_Rect){ x, y, vs->cell_length, vs->cell_length };
		draw_rect(vs, &rect, color);
	}
}

void		draw_plateau(t_vs *vs)
{
	int	y;
	int	x;

	y = 0;
	while (y < vs->plateau->height)
	{
		x = 0;
		while (x < vs->plateau->width)
		{
			draw_cell(vs,
				vs->x + x * vs->cell_shift,
				vs->y + y * vs->cell_shift,
				get_color(vs->plateau->map[y][x]));
			x++;
		}
		y++;
	}
}
