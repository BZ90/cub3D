/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_is_valid_space.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:50:03 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/16 08:48:15 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

bool	is_valid_space_utily(t_map *map, int y, int x)
{
	if (x == 0)
	{
		if ((map->map[y + 1][x] != ' ' && map->map[y + 1][x] != '1') || \
		(map->map[y][x + 1] != ' ' && map->map[y][x + 1] != '1'))
			return (false);
	}
	else if (map->map[y][x + 1] == '\0')
	{
		if ((map->map[y + 1][x] != ' ' && map->map[y + 1][x] != '1') || \
		(map->map[y][x - 1] != ' ' && map->map[y][x - 1] != '1'))
			return (false);
	}
	else
	{
		if ((map->map[y + 1][x] != ' ' && map->map[y + 1][x] != '1') || \
		(map->map[y][x - 1] != ' ' && map->map[y][x - 1] != '1') || \
		(map->map[y][x + 1] != ' ' && map->map[y][x + 1] != '1'))
			return (false);
	}
	return (true);
}

bool	is_valid_space_utily1(t_map *map, int y, int x)
{
	if (x == 0)
	{
		if ((map->map[y - 1][x] != ' ' && map->map[y - 1][x] != '1') || \
		(map->map[y][x + 1] != ' ' && map->map[y][x + 1] != '1'))
			return (false);
	}
	else if (map->map[y][x + 1] == '\0')
	{
		if ((map->map[y - 1][x] != ' ' && map->map[y - 1][x] != '1') || \
		(map->map[y][x - 1] != ' ' && map->map[y][x - 1] != '1'))
			return (false);
	}
	else
	{
		if ((map->map[y - 1][x] != ' ' && map->map[y - 1][x] != '1') || \
		(map->map[y][x - 1] != ' ' && map->map[y][x - 1] != '1') || \
		(map->map[y][x + 1] != ' ' && map->map[y][x + 1] != '1'))
			return (false);
	}
	return (true);
}

bool	is_valid_space_utilx(t_map *map, int y, int x)
{
	if (y == 0)
	{
		if ((map->map[y + 1][x] != ' ' && map->map[y + 1][x] != '1') || \
		(map->map[y][x + 1] != ' ' && map->map[y][x + 1] != '1'))
			return (false);
	}
	else if (map->map[y + 1] == NULL)
	{
		if ((map->map[y - 1][x] != ' ' && map->map[y - 1][x] != '1') || \
		(map->map[y][x + 1] != ' ' && map->map[y][x + 1] != '1'))
			return (false);
	}
	else
	{
		if ((map->map[y + 1][x] != ' ' && map->map[y + 1][x] != '1') || \
		(map->map[y - 1][x] != ' ' && map->map[y - 1][x] != '1') || \
		(map->map[y][x + 1] != ' ' && map->map[y][x + 1] != '1'))
			return (false);
	}
	return (true);
}

bool	is_valid_space_utilx1(t_map *map, int y, int x)
{
	if (y == 0)
	{
		if ((map->map[y + 1][x] != ' ' && map->map[y + 1][x] != '1') || \
		(map->map[y][x - 1] != ' ' && map->map[y][x - 1] != '1'))
			return (false);
	}
	else if (map->map[y + 1] == NULL)
	{
		if ((map->map[y - 1][x] != ' ' && map->map[y - 1][x] != '1') || \
		(map->map[y][x - 1] != ' ' && map->map[y][x - 1] != '1'))
			return (false);
	}
	else
	{
		if ((map->map[y + 1][x] != ' ' && map->map[y + 1][x] != '1') || \
		(map->map[y - 1][x] != ' ' && map->map[y - 1][x] != '1') || \
		(map->map[y][x - 1] != ' ' && map->map[y][x - 1] != '1'))
			return (false);
	}
	return (true);
}

bool	is_valid_space(t_map *map, int y, int x)
{
	if (y == 0)
	{
		if (is_valid_space_utily(map, y, x) == false)
			return (false);
	}
	else if (map->map[y + 1] == NULL)
	{
		if (is_valid_space_utily1(map, y, x) == false)
			return (false);
	}
	else if (x == 0)
	{
		if (is_valid_space_utilx(map, y, x) == false)
			return (false);
	}
	else if (map->map[y][x + 1] == '\0')
	{
		if (is_valid_space_utilx1(map, y, x) == false)
			return (false);
	}
	else if (!is_out_char(map->map[y + 1][x]) || \
	!is_out_char(map->map[y - 1][x]) || !is_out_char(map->map[y][x - 1]) || \
	!is_out_char(map->map[y][x + 1]))
		return (false);
	return (true);
}
