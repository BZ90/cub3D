/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:33:35 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/09 11:34:49 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

bool	opening_door(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'o')
				return (true);
			++x;
		}
		++y;
	}
	return (false);
}

static int	shut_up_down_doors(t_cub *cub)
{
	if (cub->player->direction.angle >= PI * 1.25 && \
		cub->player->direction.angle <= PI * 1.75)
	{
		if (cub->map->map[(int)cub->player->y - 1][(int)cub->player->x] == 'd')
			cub->map->map[(int)cub->player->y - 1][(int)cub->player->x] = 'D';
		else
			return (0);
	}
	else if (cub->player->direction.angle >= PI * 0.25 && \
		cub->player->direction.angle <= PI * 0.75)
	{
		if (cub->map->map[(int)cub->player->y + 1][(int)cub->player->x] == 'd')
			cub->map->map[(int)cub->player->y + 1][(int)cub->player->x] = 'D';
		else
			return (0);
	}
	return (1);
}

static int	shut_door(t_cub *cub)
{
	if ((cub->player->direction.angle >= PI * 1.75 && \
		cub->player->direction.angle <= PI * 2) || \
		(cub->player->direction.angle >= 0 && \
		cub->player->direction.angle <= PI * 0.25))
	{
		if (cub->map->map[(int)cub->player->y][(int)cub->player->x + 1] == 'd')
			cub->map->map[(int)cub->player->y][(int)cub->player->x + 1] = 'D';
		else
			return (0);
	}
	else if (cub->player->direction.angle >= PI * 0.75 && \
		cub->player->direction.angle <= PI * 1.25)
	{
		if (cub->map->map[(int)cub->player->y][(int)cub->player->x - 1] == 'd')
			cub->map->map[(int)cub->player->y][(int)cub->player->x - 1] = 'D';
		else
			return (0);
	}
	else
		if (shut_up_down_doors(cub) == 0)
			return (0);
	return (1);
}

static void	open_s_w_doors(t_cub *cub)
{
	if (cub->player->direction.angle >= PI * 0.75 && \
		cub->player->direction.angle <= PI * 1.25)
	{
		if (cub->map->map[(int)cub->player->y][(int)cub->player->x - 1] == 'D')
			cub->map->map[(int)cub->player->y][(int)cub->player->x - 1] = 'o';
	}
	else if (cub->player->direction.angle >= PI * 0.25 && \
		cub->player->direction.angle <= PI * 0.75)
	{
		if (cub->map->map[(int)cub->player->y + 1][(int)cub->player->x] == 'D')
			cub->map->map[(int)cub->player->y + 1][(int)cub->player->x] = 'o';
	}
}

void	open_door(t_cub *cub)
{
	if (shut_door(cub))
		return ;
	if (opening_door(cub->map->map))
		return ;
	if ((cub->player->direction.angle >= PI * 1.75 && \
		cub->player->direction.angle <= PI * 2) || \
		(cub->player->direction.angle >= 0 && \
		cub->player->direction.angle <= PI * 0.25))
	{
		if (cub->map->map[(int)cub->player->y][(int)cub->player->x + 1] == 'D')
			cub->map->map[(int)cub->player->y][(int)cub->player->x + 1] = 'o';
	}
	else if (cub->player->direction.angle >= PI * 1.25 && \
		cub->player->direction.angle <= PI * 1.75)
	{
		if (cub->map->map[(int)cub->player->y - 1][(int)cub->player->x] == 'D')
			cub->map->map[(int)cub->player->y - 1][(int)cub->player->x] = 'o';
	}
	else if (cub->player->direction.angle >= PI * 0.25 && \
		cub->player->direction.angle <= PI * 1.25)
		open_s_w_doors(cub);
}
