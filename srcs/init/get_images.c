/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:50:21 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/16 11:04:20 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

static void	open_images(t_cub *cub)
{
	cub->images->s_wall->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlxptr, \
		cub->map->s_wall_path, &cub->images->s_wall->width, \
		&cub->images->s_wall->height);
	cub->images->n_wall->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlxptr, \
		cub->map->n_wall_path, &cub->images->n_wall->width, \
		&cub->images->n_wall->height);
	cub->images->w_wall->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlxptr, \
		cub->map->w_wall_path, &cub->images->w_wall->width, \
		&cub->images->w_wall->height);
	cub->images->e_wall->img_ptr = mlx_xpm_file_to_image(cub->mlx->mlxptr, \
		cub->map->e_wall_path, &cub->images->e_wall->width, \
		&cub->images->e_wall->height);
}

static void	get_image_addresses(t_cub *cub)
{
	cub->images->e_wall->address = mlx_get_data_addr(\
		cub->images->e_wall->img_ptr, &cub->images->e_wall->bits_per_pixel, \
		&cub->images->e_wall->line_size, &cub->images->e_wall->endian);
	cub->images->w_wall->address = mlx_get_data_addr(\
		cub->images->w_wall->img_ptr, &cub->images->w_wall->bits_per_pixel, \
		&cub->images->w_wall->line_size, &cub->images->w_wall->endian);
	cub->images->n_wall->address = mlx_get_data_addr(\
		cub->images->n_wall->img_ptr, &cub->images->n_wall->bits_per_pixel, \
		&cub->images->n_wall->line_size, &cub->images->n_wall->endian);
	cub->images->s_wall->address = mlx_get_data_addr(\
		cub->images->s_wall->img_ptr, &cub->images->s_wall->bits_per_pixel, \
		&cub->images->s_wall->line_size, &cub->images->s_wall->endian);
}

int	get_images(t_cub *cub)
{
	open_images(cub);
	if (cub->images->s_wall->img_ptr == NULL || \
		cub->images->n_wall->img_ptr == NULL || \
		cub->images->e_wall->img_ptr == NULL || \
		cub->images->w_wall->img_ptr == NULL)
		return (-1);
	get_image_addresses(cub);
	if (cub->images->e_wall->address == NULL || \
		cub->images->w_wall->address == NULL || \
		cub->images->n_wall->address == NULL || \
		cub->images->s_wall->address == NULL)
		return (-1);
	if (init_doors(cub) == -1)
		return (-1);
	return (0);
}

void	init_images(t_images *cub)
{
	cub->e_wall = malloc(sizeof(t_image));
	cub->n_wall = malloc(sizeof(t_image));
	cub->s_wall = malloc(sizeof(t_image));
	cub->w_wall = malloc(sizeof(t_image));
	cub->door1 = malloc(sizeof(t_image));
	cub->door2 = malloc(sizeof(t_image));
	cub->door3 = malloc(sizeof(t_image));
	cub->door4 = malloc(sizeof(t_image));
	cub->door5 = malloc(sizeof(t_image));
	cub->door6 = malloc(sizeof(t_image));
	cub->door7 = malloc(sizeof(t_image));
	set_images_null(cub);
	cub->main_image = malloc(sizeof(t_image));
	init_main_image(cub->main_image, cub->mlx);
}
