/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:57:06 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/12 14:47:27 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include <errno.h>

int	main(int argc, char **argv)
{
	t_vs	*vs;

	(void)argv;
	if (argc == 1)
	{
		errno = 0;
		vs = init_vs();
		parse(vs);
		while (vs->plateau && !vs->close)
		{
			check_event(vs);
			calc_dimensions(vs, vs->plateau);
			count_players(vs, vs->plateau);
			draw_background(vs);
			draw_status(vs);
			draw_plateau(vs);
			SDL_UpdateWindowSurface(vs->window);
			SDL_Delay(1000 / 60);
		}
		close(vs);
	}
	else
		print_usage();
	return (EXIT_SUCCESS);
}
