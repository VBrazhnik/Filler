/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:55:45 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/04/06 15:30:21 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	validate_piece_size(char **strsplit)
{
	if (ft_strsplit_len(strsplit) != 3
		|| ft_strcmp(strsplit[0], "Piece")
		|| ft_atoi(strsplit[1]) < 1
		|| ft_atoi(strsplit[2]) < 1
		|| !ft_strstr(strsplit[2], ":"))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			parse_piece_size(t_piece *piece)
{
	char	*line;
	char	**strsplit;

	line = NULL;
	strsplit = NULL;
	if (get_next_line(0, &line) != 1
		|| !(strsplit = ft_strsplit(line, ' '))
		|| validate_piece_size(strsplit) != EXIT_SUCCESS)
	{
		ft_strdel(&line);
		ft_strsplit_free(&strsplit);
		return (EXIT_FAILURE);
	}
	piece->height = ft_atoi(strsplit[1]);
	piece->width = ft_atoi(strsplit[2]);
	ft_strdel(&line);
	ft_strsplit_free(&strsplit);
	return (EXIT_SUCCESS);
}
