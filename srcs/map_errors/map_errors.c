/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:58:18 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/16 08:52:51 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

bool	is_valid_wall(t_map *map, int y, int x)
{
	if (y == 0)
	{
		if (is_valid_wall_utily(map, x, y) == false)
			return (false);
	}
	else if (map->map[y + 1] == NULL)
	{
		if (is_valid_wall_utily1(map, x, y) == false)
			return (false);
	}
	else if (x == 0)
	{
		if (is_valid_wall_utilx(map, x, y) == false)
			return (false);
	}
	else if (map->map[y][x + 1] == '\0')
	{
		if (is_valid_wall_utilx1(map, x, y) == false)
			return (false);
	}
	else
		if (is_valid_wall_util(map, x, y) == false)
			return (false);
	return (true);
}

bool	is_valid_tile(t_map *map, int y, int x)
{
	if (y == 0)
		return (false);
	else if (map->map[y + 1] == NULL)
		return (false);
	else if (x == 0)
		return (false);
	else if (map->map[y][x + 1] == '\0')
		return (false);
	else if (map->map[y - 1][x] == ' ' || \
	map->map[y + 1][x] == ' ' || \
	map->map[y][x - 1] == ' ' || \
	map->map[y][x + 1] == ' ')
		return (false);
	return (true);
}

int	check_error(t_map *map, t_map_err *m, int i, int j)
{
	if (map->map[i][j] == '1')
	{
		m->valid_wall = is_valid_wall(map, i, j);
		if (m->valid_wall == false)
			return (1);
	}
	else if (map->map[i][j] == ' ')
	{
		m->valid_space = is_valid_space(map, i, j);
		if (m->valid_space == false)
			return (1);
	}
	else
	{
		m->valid_other = is_valid_tile(map, i, j);
		if (m->valid_other == false)
			return (1);
	}
	return (0);
}

int	map_errors(t_map *map, int i, int j)
{
	t_map_err	m;

	if (initial_error(map) == 1)
		return (1);
	init_map_err(&m);
	while (1)
	{
		if (map->map[i][j] == '\0')
		{
			j = 0;
			++i;
		}
		if (map->map[i] == NULL)
			break ;
		if (map->map[i][j] == 'N' || map->map[i][j] == 'E' || \
		map->map[i][j] == 'S' || map->map[i][j] == 'W')
			++m.player_count;
		if (check_error(map, &m, i, j) == 1)
			break ;
		++j;
	}
	return (is_error(m));
}
