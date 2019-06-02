/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 19:38:11 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/11 19:38:11 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

static t_plateau	*get_next_plateau(t_vs *vs)
{
	if (!vs->plateau->next)
		parse(vs);
	return ((vs->plateau->next) ? vs->plateau->next : vs->plateau);
}

void				check_event(t_vs *vs)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			vs->close = true;
		else if (event.type == SDL_KEYDOWN
			&& event.key.keysym.scancode == SDL_SCANCODE_SPACE)
			vs->pause = !(vs->pause);
		else if (event.type == SDL_KEYDOWN
			&& event.key.keysym.scancode == SDL_SCANCODE_LEFT
			&& vs->plateau->previous)
		{
			vs->pause = true;
			vs->plateau = vs->plateau->previous;
		}
		else if (event.type == SDL_KEYDOWN
			&& event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			vs->pause = true;
			vs->plateau = get_next_plateau(vs);
		}
	}
	if (!vs->pause)
		vs->plateau = get_next_plateau(vs);
}
