/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:34:44 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/11 17:09:25 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	validate_player(char **strsplit)
{
	if (ft_strsplit_len(strsplit) != 5
		|| ft_strcmp(strsplit[0], "$$$")
		|| ft_strcmp(strsplit[1], "exec")
		|| (ft_strcmp(strsplit[2], "p1") && ft_strcmp(strsplit[2], "p2"))
		|| ft_strcmp(strsplit[3], ":")
		|| strsplit[4][0] != '['
		|| !ft_strstr(strsplit[4], "vbrazhni.filler]"))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			parse_player(t_filler *filler)
{
	char	*line;
	char	**strsplit;

	line = NULL;
	strsplit = NULL;
	if (get_next_line(0, &line) != 1
		|| !(strsplit = ft_strsplit(line, ' '))
		|| validate_player(strsplit) != EXIT_SUCCESS)
	{
		ft_strdel(&line);
		ft_strsplit_free(&strsplit);
		return (EXIT_FAILURE);
	}
	filler->player_symbol = (!ft_strcmp(strsplit[2], "p1")) ? 'O' : 'X';
	filler->enemy_symbol = (!ft_strcmp(strsplit[2], "p1")) ? 'X' : 'O';
	ft_strdel(&line);
	ft_strsplit_free(&strsplit);
	return (EXIT_SUCCESS);
}
