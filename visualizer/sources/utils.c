/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:46:59 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/11 19:47:40 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void	close(t_vs *vs)
{
	SDL_FreeSurface(vs->surface);
	SDL_DestroyWindow(vs->window);
	SDL_Quit();
}

void	terminate(const char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(EXIT_FAILURE);
}
