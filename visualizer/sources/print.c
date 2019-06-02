/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:41:01 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/31 22:11:51 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void	print_usage(void)
{
	ft_putstr("Usage: ./filler_vm -f MAP_FILE");
	ft_putendl(" -p1 PLAYER_FILE -p2 PLAYER_FILE | ./vs");
	ft_putendl(NULL);
	ft_putendl("Control keys:");
	ft_putendl("> Space       — start/stop");
	ft_putendl("> Right Arrow — next step");
	ft_putendl("> Left Arrow  — previous step");
}
