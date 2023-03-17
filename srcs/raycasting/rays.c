/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:09:30 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/10 12:01:08 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	pick_texture(t_cub *cub, t_ray *ray_data)
{
	if (ray_data->door == 1)
		ray_data->texture = cub->images->door1;
	else if (ray_data->door == 2)
		ray_data->texture = cub->images->curdoor;
	else if (ray_data->side == true)
	{
		if (ray_data->step_x > 0)
			ray_data->texture = cub->images->e_wall;
		else
			ray_data->texture = cub->images->w_wall;
	}
	else
	{
		if (ray_data->step_y > 0)
			ray_data->texture = cub->images->s_wall;
		else
			ray_data->texture = cub->images->n_wall;
	}
}

void	draw_ray(t_cub *cub, t_ray *ray_data)
{
	ray_data->wall_height = (int)(HEIGHT / ray_data->wall_dist);
	pick_texture(cub, ray_data);
	ray_data->texture_x = (int)(ray_data->wall_x * \
	(double)(ray_data->texture->width));
	if ((ray_data->side == true && ray_data->step_x == -1) || \
		(ray_data->side == false && ray_data->step_y == 1))
		ray_data->texture_x = ray_data->texture->width - ray_data->texture_x;
	put_image_line(cub, ray_data);
}

void	cast_ray(t_cub *cub, t_ray *ray_data)
{
	while (ray_data->hit == false)
	{
		if (ray_data->side_dist_x < ray_data->side_dist_y)
		{
			ray_data->side_dist_x += ray_data->delta_x;
			ray_data->side = 1;
			ray_data->ray_x += ray_data->step_x;
		}
		else
		{
			ray_data->side_dist_y += ray_data->delta_y;
			ray_data->side = 0;
			ray_data->ray_y += ray_data->step_y;
		}
		if (cub->map->map[ray_data->ray_y][ray_data->ray_x] == '1' || \
		cub->map->map[ray_data->ray_y][ray_data->ray_x] == 'D' || \
		cub->map->map[ray_data->ray_y][ray_data->ray_x] == 'o')
			ray_data->hit = true;
		if (cub->map->map[ray_data->ray_y][ray_data->ray_x] == 'D')
			ray_data->door = 1;
		if (cub->map->map[ray_data->ray_y][ray_data->ray_x] == 'o')
			ray_data->door = 2;
	}
	ray_cast_ifelse(cub, ray_data);
	ray_data->wall_x -= floor(ray_data->wall_x);
}

void	init_ray_data(t_cub *cub, t_ray *ray_data)
{
	ray_data->hit = false;
	ray_data->door = false;
	ray_data->wall_dist = 0;
	ray_data->camera_x = ((2 * (double)ray_data->cur_ray) / \
	(double)WIDTH - 1) * 0.8;
	ray_data->ray_dir_x = cub->player->direction.x - \
	(cub->player->direction.y * (ray_data->camera_x));
	ray_data->ray_dir_y = cub->player->direction.y + \
	(cub->player->direction.x * (ray_data->camera_x));
	ray_data->ray_x = (int)cub->player->x;
	ray_data->ray_y = (int)cub->player->y;
	init_ray_data_utils(cub, ray_data);
}

int	cast_rays(t_cub *cub)
{
	t_ray	ray_data;

	ray_data.cur_ray = 0;
	while (ray_data.cur_ray < WIDTH)
	{
		init_ray_data(cub, &ray_data);
		cast_ray(cub, &ray_data);
		draw_ray(cub, &ray_data);
		++ray_data.cur_ray;
	}
	mlx_put_image_to_window(cub->mlx->mlxptr, cub->mlx->winptr, \
	cub->mlx->image, 0, 0);
	return (0);
}
