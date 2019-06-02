/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:34:32 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/04/06 17:34:32 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coords(t_filler *filler)
{
	ft_putnbr(filler->y);
	ft_putchar(' ');
	ft_putnbr(filler->x);
	ft_putchar('\n');
}
