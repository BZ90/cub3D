/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:54:20 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/09 11:43:20 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	set_door_open(char **map)
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
			{
				map[y][x] = 'd';
				return ;
			}
			++x;
		}
		++y;
	}
}

void	open_door_images(t_cub *cub)
{
	cub->images->door1->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlxptr, \
		"./images/door/1.xpm", \
		&cub->images->door1->width, &cub->images->door1->height);
	cub->images->door2->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlxptr, \
		"./images/door/2.xpm", \
		&cub->images->door2->width, &cub->images->door2->height);
	cub->images->door3->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlxptr, \
		"./images/door/3.xpm", \
		&cub->images->door3->width, &cub->images->door3->height);
	cub->images->door4->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlxptr, \
		"./images/door/4.xpm", \
		&cub->images->door4->width, &cub->images->door4->height);
	cub->images->door5->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlxptr, \
		"./images/door/5.xpm", \
		&cub->images->door5->width, &cub->images->door5->height);
	cub->images->door6->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlxptr, \
		"./images/door/6.xpm", \
		&cub->images->door6->width, &cub->images->door6->height);
	cub->images->door7->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlxptr, \
		"./images/door/7.xpm", \
		&cub->images->door7->width, &cub->images->door7->height);
}

void	get_door_addresses(t_cub *cub)
{
	cub->images->door1->address = mlx_get_data_addr(\
		cub->images->door1->img_ptr, &cub->images->door1->bits_per_pixel, \
		&cub->images->door1->line_size, &cub->images->door1->endian);
	cub->images->door2->address = mlx_get_data_addr(\
		cub->images->door2->img_ptr, &cub->images->door2->bits_per_pixel, \
		&cub->images->door2->line_size, &cub->images->door2->endian);
	cub->images->door3->address = mlx_get_data_addr(\
		cub->images->door3->img_ptr, &cub->images->door3->bits_per_pixel, \
		&cub->images->door3->line_size, &cub->images->door3->endian);
	cub->images->door4->address = mlx_get_data_addr(\
		cub->images->door4->img_ptr, &cub->images->door4->bits_per_pixel, \
		&cub->images->door4->line_size, &cub->images->door4->endian);
	cub->images->door5->address = mlx_get_data_addr(\
		cub->images->door5->img_ptr, &cub->images->door5->bits_per_pixel, \
		&cub->images->door5->line_size, &cub->images->door5->endian);
	cub->images->door6->address = mlx_get_data_addr(\
		cub->images->door6->img_ptr, &cub->images->door6->bits_per_pixel, \
		&cub->images->door6->line_size, &cub->images->door6->endian);
	cub->images->door7->address = mlx_get_data_addr(\
		cub->images->door7->img_ptr, &cub->images->door7->bits_per_pixel, \
		&cub->images->door7->line_size, &cub->images->door7->endian);
}

int	init_doors(t_cub *cub)
{
	open_door_images(cub);
	if (cub->images->door1->img_ptr == NULL || \
	cub->images->door2->img_ptr == NULL || \
	cub->images->door3->img_ptr == NULL || \
	cub->images->door4->img_ptr == NULL || \
	cub->images->door5->img_ptr == NULL || \
	cub->images->door6->img_ptr == NULL || \
	cub->images->door7->img_ptr == NULL)
		return (-1);
	cub->images->curdoor = cub->images->door1;
	get_door_addresses(cub);
	if (cub->images->door1->address == NULL || \
		cub->images->door2->address == NULL || \
		cub->images->door3->address == NULL || \
		cub->images->door4->address == NULL || \
		cub->images->door5->address == NULL || \
		cub->images->door6->address == NULL || \
		cub->images->door7->address == NULL)
		return (-1);
	return (0);
}
