/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:04:04 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/16 11:05:00 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	ray_cast_ifelse(t_cub *cub, t_ray *ray_data)
{
	if (ray_data->side == 1)
	{
		ray_data->wall_dist = ray_data->side_dist_x - ray_data->delta_x;
		ray_data->wall_x = cub->player->y + \
		(ray_data->wall_dist * ray_data->ray_dir_y);
	}
	else
	{
		ray_data->wall_dist = ray_data->side_dist_y - ray_data->delta_y;
		ray_data->wall_x = cub->player->x + \
		(ray_data->wall_dist * ray_data->ray_dir_x);
	}
}

void	inti_ray_data_utils_two(t_cub *cub, t_ray *ray_data)
{
	if (ray_data->ray_dir_y < 0)
	{
		ray_data->side_dist_y = (cub->player->y - ray_data->ray_y) * \
		ray_data->delta_y;
		ray_data->step_y = -1;
	}
	else
	{
		ray_data->side_dist_y = (ray_data->ray_y + 1 - cub->player->y) * \
		ray_data->delta_y;
		ray_data->step_y = 1;
	}
}

void	init_ray_data_utils(t_cub *cub, t_ray *ray_data)
{
	if (ray_data->ray_dir_x == 0.0)
		ray_data->delta_x = 1e30;
	else
		ray_data->delta_x = fabs(1 / ray_data->ray_dir_x);
	if (ray_data->ray_dir_y == 0.0)
		ray_data->delta_y = 1e30;
	else
		ray_data->delta_y = fabs(1 / ray_data->ray_dir_y);
	if (ray_data->ray_dir_x < 0)
	{
		ray_data->side_dist_x = (cub->player->x - ray_data->ray_x) * \
		ray_data->delta_x;
		ray_data->step_x = -1;
	}
	else
	{
		ray_data->side_dist_x = (ray_data->ray_x + 1 - cub->player->x) * \
		ray_data->delta_x;
		ray_data->step_x = 1;
	}
	inti_ray_data_utils_two(cub, ray_data);
}
