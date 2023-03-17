/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:58:58 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/16 11:01:25 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	init_map(t_map *map)
{
	map->n_wall_path = NULL;
	map->w_wall_path = NULL;
	map->e_wall_path = NULL;
	map->s_wall_path = NULL;
	map->map = NULL;
	map->floor = 0;
	map->ceiling = 0;
	map->height = 0;
	map->width = 0;
	map->colour_error = false;
	map->did_floor = false;
	map->did_ceil = false;
	map->invalid_key = false;
	map->duplicate_key = false;
}

void	init_minimap(t_cub *cub)
{
	t_td	*test;

	test = malloc(sizeof(t_td));
	test->img = malloc(sizeof(t_image));
	test->mlx = cub->mlx;
	minimap_image(test);
	test->player = cub->player;
	test->map = cub->map;
	cub->mini = test;
}
