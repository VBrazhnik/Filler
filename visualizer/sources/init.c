/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 19:02:17 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/11 21:11:51 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include "error_message.h"

static SDL_Window	*init_window(void)
{
	SDL_Window	*window;

	if (!(window = SDL_CreateWindow("Filler",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WIDTH, HEIGHT, 0)))
		terminate(SDL_GetError());
	return (window);
}

static SDL_Surface	*init_surface(t_vs *vs)
{
	SDL_Surface	*surface;

	if (!(surface = SDL_GetWindowSurface(vs->window)))
		terminate(SDL_GetError());
	return (surface);
}

t_vs				*init_vs(void)
{
	t_vs	*vs;

	if (!(vs = (t_vs *)ft_memalloc(sizeof(t_vs))))
		terminate(ERR_VS_INIT);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		terminate(SDL_GetError());
	vs->window = init_window();
	vs->surface = init_surface(vs);
	vs->plateau = NULL;
	vs->close = false;
	vs->pause = true;
	return (vs);
}

t_plateau			*init_plateau(void)
{
	t_plateau	*plateau;

	if (!(plateau = (t_plateau *)ft_memalloc(sizeof(t_plateau))))
		terminate(ERR_PLATEAU_INIT);
	plateau->map = NULL;
	plateau->next = NULL;
	plateau->previous = NULL;
	return (plateau);
}

SDL_Color			init_color(int red, int green, int blue, int alpha)
{
	return ((SDL_Color){ (Uint8)red, (Uint8)green, (Uint8)blue, (Uint8)alpha });
}
