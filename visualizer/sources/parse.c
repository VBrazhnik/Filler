/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:24:45 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/05/11 19:46:16 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include "error_message.h"

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

static void	parse_plateau_size(t_plateau *plateau, char *line)
{
	char	**strsplit;

	if (!(strsplit = ft_strsplit(line, ' '))
		|| validate_plateau_size(strsplit) != EXIT_SUCCESS)
	{
		ft_strdel(&line);
		ft_strsplit_free(&strsplit);
		terminate(ERR_PLATEAU_SIZE);
	}
	plateau->height = ft_atoi(strsplit[1]);
	plateau->width = ft_atoi(strsplit[2]);
	ft_strdel(&line);
	ft_strsplit_free(&strsplit);
}

static int	validate_plateau_line(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] != '.'
			&& ft_toupper(line[i]) != 'O'
			&& ft_toupper(line[i]) != 'X')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	parse_plateau(t_plateau *plateau)
{
	int		y;
	char	*line;

	if (get_next_line(0, &line) != 1
		|| (int)ft_strlen(line) != plateau->width + 4)
	{
		ft_strdel(&line);
		terminate(ERR_PLATEAU);
	}
	ft_strdel(&line);
	if (!(plateau->map = (char **)ft_memalloc(
			sizeof(char *) * plateau->height)))
		terminate(ERR_PLATEAU);
	y = 0;
	while (y < plateau->height)
	{
		if (get_next_line(0, &line) != 1
			|| (int)ft_strlen(line) != plateau->width + 4
			|| validate_plateau_line(&line[4]) != EXIT_SUCCESS)
			terminate(ERR_PLATEAU);
		plateau->map[y] = ft_strdup(&line[4]);
		ft_strdel(&line);
		y++;
	}
}

void		parse(t_vs *vs)
{
	char		*line;
	t_plateau	*plateau;

	plateau = NULL;
	while (!plateau && get_next_line(0, &line) == 1)
	{
		if (ft_strstr(line, "Plateau"))
		{
			plateau = init_plateau();
			parse_plateau_size(plateau, line);
			parse_plateau(plateau);
			add_plateau(vs, plateau);
		}
		else
			ft_strdel(&line);
	}
}
