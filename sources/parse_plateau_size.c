/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:26:53 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/04/06 15:30:17 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	validate_plateau_size(char **strsplit)
{
	if (ft_strsplit_len(strsplit) != 3
		|| ft_strcmp(strsplit[0], "Plateau")
		|| ft_atoi(strsplit[1]) < 1
		|| ft_atoi(strsplit[2]) < 1
		|| !ft_strstr(strsplit[2], ":"))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			parse_plateau_size(t_plateau *plateau)
{
	char	*line;
	char	**strsplit;

	line = NULL;
	strsplit = NULL;
	if (get_next_line(0, &line) != 1
		|| !(strsplit = ft_strsplit(line, ' '))
		|| validate_plateau_size(strsplit) != EXIT_SUCCESS)
	{
		ft_strdel(&line);
		ft_strsplit_free(&strsplit);
		return (EXIT_FAILURE);
	}
	plateau->height = ft_atoi(strsplit[1]);
	plateau->width = ft_atoi(strsplit[2]);
	ft_strdel(&line);
	ft_strsplit_free(&strsplit);
	return (EXIT_SUCCESS);
}
