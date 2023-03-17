/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:52:40 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/16 11:04:32 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	init_player(t_player *cub)
{
	cub->ammo = 100;
	cub->health = 100;
	cub->x = 0;
	cub->mv_bw = false;
	cub->mv_fw = false;
	cub->mov_r = false;
	cub->mov_l = false;
	cub->mv_spd = 0.05;
	cub->rot_l = false;
	cub->rot_r = false;
	cub->rot_spd = 0.03;
}

void	init_main_image(t_image	*cub, t_mlx *m)
{
	cub->height = HEIGHT;
	cub->width = WIDTH;
	cub->mlx = m;
	cub->mlx->img_data = \
	mlx_get_data_addr(cub->mlx->image, &cub->bits_per_pixel, \
	&cub->line_size, &cub->endian);
}

void	set_images_null(t_images *cub)
{
	cub->e_wall->img_ptr = NULL;
	cub->n_wall->img_ptr = NULL;
	cub->s_wall->img_ptr = NULL;
	cub->w_wall->img_ptr = NULL;
	cub->door1->img_ptr = NULL;
	cub->door2->img_ptr = NULL;
	cub->door3->img_ptr = NULL;
	cub->door4->img_ptr = NULL;
	cub->door5->img_ptr = NULL;
	cub->door6->img_ptr = NULL;
	cub->door7->img_ptr = NULL;
}

void	initialize_cub(t_cub *cub)
{
	cub->player = malloc(sizeof(t_player));
	cub->map = malloc(sizeof(t_map));
	cub->images = malloc(sizeof(t_images));
	cub->mlx = malloc(sizeof(t_mlx));
	cub->images->mlx = cub->mlx;
	cub->player->back = cub;
	cub->map->back = cub;
	init_player(cub->player);
	init_map(cub->map);
	t_mlx_init(cub->mlx);
	init_images(cub->images);
	cub->mini = NULL;
	cub->exiting = false;
}

void	t_mlx_init(t_mlx *cub)
{
	cub->mlxptr = mlx_init();
	cub->winptr = mlx_new_window(cub->mlxptr, WIDTH, HEIGHT, "Cub3d");
	cub->image = mlx_new_image(cub->mlxptr, WIDTH, HEIGHT);
}
