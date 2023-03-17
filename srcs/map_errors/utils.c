/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:29:46 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/16 08:53:40 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	init_map_err(t_map_err *m)
{
	m->valid_other = true;
	m->valid_space = true;
	m->valid_wall = true;
	m->player_count = 0;
}

bool	is_out_char(char c)
{
	if (c == ' ' || c == '1')
		return (true);
	return (false);
}

bool	is_error(t_map_err m)
{
	if (m.valid_space == false)
	{
		ft_fprintf(2, "Error: Map: Empty space inside\n");
		return (1);
	}
	if (m.valid_wall == false)
	{
		ft_fprintf(2, "Error: Map: Invalid wall placement\n");
		return (1);
	}
	if (m.valid_other == false)
	{
		ft_fprintf(2, "Error: Map: Not surrounded by walls\n");
		return (1);
	}
	if (m.player_count != 1)
	{
		ft_fprintf(2, "Error: Map: Invalid player count\n");
		return (1);
	}
	return (0);
}

static int	initial_error_util(t_map *map)
{
	if (map->map == NULL)
	{
		ft_fprintf(2, "Error: Map: Missing map\n");
		return (1);
	}
	if (map->n_wall_path == NULL || map->s_wall_path == NULL || \
		map->e_wall_path == NULL || map->w_wall_path == NULL)
	{
		ft_fprintf(2, "Error: Map: Missing wall texture\n");
		return (1);
	}
	return (0);
}

int	initial_error(t_map *map)
{
	if (initial_error_util(map) == 1)
		return (1);
	if (map->invalid_key)
	{
		ft_fprintf(2, "Error: Map: Invalid key\n");
		return (1);
	}
	if (map->duplicate_key)
	{
		ft_fprintf(2, "Error: Map: Duplicate key\n");
		return (1);
	}
	if (map->colour_error == true || map->did_ceil == false || \
		map->did_floor == false)
	{
		ft_fprintf(2, "Error: Map: Invalid colour value\n");
		return (1);
	}
	if (p_to_p_len(map->map) < 3)
	{
		ft_fprintf(2, "Error: Map: Too small\n");
		return (1);
	}
	return (0);
}
