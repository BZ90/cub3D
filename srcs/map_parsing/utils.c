/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:59:52 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/16 09:18:33 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	up_to_map(t_cub *cub, char *line, int use_line_ret, int map_fd)
{
	if (use_line_ret == 1)
	{
		get_map(cub, map_fd, line);
		return (2);
	}
	else if (use_line_ret == -1)
		cub->map->invalid_key = true;
	return (1);
}

bool	is_only_valid_map_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'N' && line[i] != 'E' && \
		line[i] != 'S' && line[i] != 'W' && \
		line[i] != '0' && line[i] != '1' && \
		line[i] != ' ' && line[i] != '\n' && \
		line[i] != 'D' && line[i] != 'd' && \
		line[i] != 'o')
			return (false);
		++i;
	}
	return (true);
}

int	skip_identifier(char *line)
{
	int	ret;

	ret = 0;
	while (line[ret] != ' ')
		++ret;
	while (line[ret] == ' ')
		++ret;
	return (ret);
}

void	set_direction(t_cub *cub, char c)
{
	if (c == 'N')
		cub->player->direction.angle = PI * 1.5;
	if (c == 'S')
		cub->player->direction.angle = PI / 2;
	if (c == 'E')
		cub->player->direction.angle = 0;
	if (c == 'W')
		cub->player->direction.angle = PI;
}

void	get_player_start_direction(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map->map[i])
	{
		j = -1;
		while (cub->map->map[i][++j])
			if (cub->map->map[i][j] == 'N' || cub->map->map[i][j] == 'S' || \
			cub->map->map[i][j] == 'E' || cub->map->map[i][j] == 'W')
				break ;
		if (cub->map->map[i][j] == 'N' || cub->map->map[i][j] == 'S' || \
			cub->map->map[i][j] == 'E' || cub->map->map[i][j] == 'W')
			break ;
		++i;
	}
	if (cub->map->map[i] == NULL)
		return ;
	set_direction(cub, cub->map->map[i][j]);
	cub->player->direction.x = cos(cub->player->direction.angle);
	cub->player->direction.y = sin(cub->player->direction.angle);
	cub->player->x = j + 0.5;
	cub->player->y = i + 0.5;
	return ;
}
