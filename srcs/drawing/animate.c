/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:42:48 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/09 11:44:51 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

static void	animate_door(t_cub *cub, int spin_count)
{
	if (opening_door(cub->map->map))
	{
		while (spin_count-- > 0)
		{
			cub->images->curdoor = cub->images->door1;
			usleep(100000);
			cub->images->curdoor = cub->images->door2;
			usleep(100000);
			cub->images->curdoor = cub->images->door3;
			usleep(100000);
		}
		cub->images->curdoor = cub->images->door1;
		usleep(100000);
		cub->images->curdoor = cub->images->door4;
		usleep(100000);
		cub->images->curdoor = cub->images->door5;
		usleep(100000);
		cub->images->curdoor = cub->images->door6;
		usleep(100000);
		cub->images->curdoor = cub->images->door7;
		usleep(100000);
		set_door_open(cub->map->map);
	}
}

void	*animate(void *arg)
{
	t_cub	*cub;

	cub = (t_cub *)arg;
	while (1)
	{
		animate_door(cub, 5);
		if (cub->exiting == true)
			return (NULL);
	}
}
