/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 19:01:17 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/12 14:12:51 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

SDL_Color	get_color(char symbol)
{
	if (symbol == 'o')
		return (init_color(210, 138, 133, 255));
	else if (symbol == 'O')
		return (init_color(200, 53, 48, 255));
	else if (symbol == 'x')
		return (init_color(157, 191, 223, 255));
	else if (symbol == 'X')
		return (init_color(78, 150, 207, 255));
	else
		return (init_color(215, 215, 215, 255));
}
