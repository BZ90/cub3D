/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_is_valid_wall_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:22:05 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/16 08:53:33 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

bool	is_valid_wall_utily(t_map *map, int x, int y)
{
	if (x == 0)
	{
		if (!is_out_char(map->map[y][x + 1]) || \
		!is_out_char(map->map[y + 1][x]))
			return (false);
	}
	else if (map->map[y][x + 1] == '\0')
	{
		if (!is_out_char(map->map[y][x - 1]) || \
		!is_out_char(map->map[y + 1][x]))
			return (false);
	}
	else
	{
		if (!is_out_char(map->map[y][x + 1]) || \
		!is_out_char(map->map[y][x - 1]))
			return (false);
		if (!is_out_char(map->map[y + 1][x]))
		{
			if (map->map[y][x + 1] != '1' || \
			map->map[y][x - 1] != '1')
				return (false);
		}
	}
	return (true);
}

bool	is_valid_wall_utily1(t_map *map, int x, int y)
{
	if (x == 0)
	{
		if (!is_out_char(map->map[y][x + 1]) || \
		!is_out_char(map->map[y - 1][x]))
			return (false);
	}
	else if (map->map[y][x + 1] == '\0')
	{
		if (!is_out_char(map->map[y][x - 1]) || \
		!is_out_char(map->map[y - 1][x]))
			return (false);
	}
	else
	{
		if (!is_out_char(map->map[y][x + 1]) || \
		!is_out_char(map->map[y][x - 1]))
			return (false);
		if (!is_out_char(map->map[y - 1][x]))
		{
			if (map->map[y][x + 1] != '1' || map->map[y][x - 1] != '1')
				return (false);
		}
	}
	return (true);
}

bool	is_valid_wall_utilx(t_map *map, int x, int y)
{
	if (y == 0)
	{
		if (!is_out_char(map->map[y][x + 1]) || \
		!is_out_char(map->map[y + 1][x]))
			return (false);
	}
	else if (map->map[y + 1] == NULL)
	{
		if (!is_out_char(map->map[y][x + 1]) || \
		!is_out_char(map->map[y - 1][x]))
			return (false);
	}
	else
	{
		if (!is_out_char(map->map[y + 1][x]) || \
		!is_out_char(map->map[y - 1][x]))
			return (false);
		if (!is_out_char(map->map[y][x + 1]))
		{
			if (map->map[y - 1][x] != '1' || map->map[y + 1][x] != '1')
				return (false);
		}
	}
	return (true);
}

bool	is_valid_wall_utilx1(t_map *map, int x, int y)
{
	if (y == 0)
	{
		if (!is_out_char(map->map[y][x - 1]) || \
		!is_out_char(map->map[y + 1][x]))
			return (false);
	}
	else if (map->map[y + 1] == NULL)
	{
		if (!is_out_char(map->map[y][x - 1]) || \
		!is_out_char(map->map[y - 1][x]))
			return (false);
	}
	else
	{
		if (!is_out_char(map->map[y + 1][x]) || \
		!is_out_char(map->map[y - 1][x]))
			return (false);
		if (!is_out_char(map->map[y][x - 1]))
		{
			if (map->map[y - 1][x] != '1' || map->map[y + 1][x] != '1')
				return (false);
		}
	}
	return (true);
}

bool	is_valid_wall_util(t_map *map, int x, int y)
{
	if (!is_out_char(map->map[y - 1][x]))
	{
		if (map->map[y][x + 1] == ' ' || map->map[y][x - 1] == ' ')
			return (false);
	}
	if (!is_out_char(map->map[y + 1][x]))
	{
		if (map->map[y][x + 1] == ' ' || map->map[y][x - 1] == ' ')
			return (false);
	}
	if (!is_out_char(map->map[y][x - 1]))
	{
		if (map->map[y - 1][x] == ' ' || map->map[y + 1][x] == ' ')
			return (false);
	}
	if (!is_out_char(map->map[y][x + 1]))
	{
		if (map->map[y - 1][x] == ' ' || map->map[y + 1][x] == ' ')
			return (false);
	}
	return (true);
}
