/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:51:47 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/12 16:15:58 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void	add_plateau(t_vs *vs, t_plateau *plateau)
{
	t_plateau	*previous;

	if (vs->plateau)
	{
		previous = vs->plateau;
		while (previous->next)
			previous = previous->next;
		previous->next = plateau;
		plateau->previous = previous;
	}
	else
		vs->plateau = plateau;
}
