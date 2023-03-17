/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:45:09 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/10 09:33:36 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	free_p_to_p(char **ptp)
{
	int	i;

	if (!ptp)
		return ;
	i = -1;
	while (ptp[++i])
		free(ptp[i]);
	free(ptp);
}

void	destroy_images(t_cub *cub)
{
	if (cub->images && cub->images->e_wall->img_ptr)
	{
		mlx_destroy_image(cub->mlx->mlxptr, cub->images->n_wall->img_ptr);
		mlx_destroy_image(cub->mlx->mlxptr, cub->images->e_wall->img_ptr);
		mlx_destroy_image(cub->mlx->mlxptr, cub->images->s_wall->img_ptr);
		mlx_destroy_image(cub->mlx->mlxptr, cub->images->w_wall->img_ptr);
		mlx_destroy_image(cub->mlx->mlxptr, cub->images->door1->img_ptr);
		mlx_destroy_image(cub->mlx->mlxptr, cub->images->door2->img_ptr);
		mlx_destroy_image(cub->mlx->mlxptr, cub->images->door3->img_ptr);
		mlx_destroy_image(cub->mlx->mlxptr, cub->images->door4->img_ptr);
		mlx_destroy_image(cub->mlx->mlxptr, cub->images->door5->img_ptr);
		mlx_destroy_image(cub->mlx->mlxptr, cub->images->door6->img_ptr);
		mlx_destroy_image(cub->mlx->mlxptr, cub->images->door7->img_ptr);
	}
	if (cub->mlx->image)
		mlx_destroy_image(cub->mlx->mlxptr, cub->mlx->image);
	if (cub->mini)
		mlx_destroy_image(cub->mlx->mlxptr, cub->mini->img->img_ptr);
}

void	free_images(t_cub *cub)
{
	if (cub->images->main_image)
		free(cub->images->main_image);
	if (cub->images->n_wall)
		free(cub->images->n_wall);
	if (cub->images->e_wall)
		free(cub->images->e_wall);
	if (cub->images->s_wall)
		free(cub->images->s_wall);
	if (cub->images->w_wall)
		free(cub->images->w_wall);
	if (cub->images->door1)
		free(cub->images->door1);
	if (cub->images->door2)
		free(cub->images->door2);
	if (cub->images->door3)
		free(cub->images->door3);
	if (cub->images->door4)
		free(cub->images->door4);
	if (cub->images->door5)
		free(cub->images->door5);
	if (cub->images->door6)
		free(cub->images->door6);
	if (cub->images->door7)
		free(cub->images->door7);
	free(cub->images);
}

static void	free_map(t_cub *cub)
{
	if (cub->map->n_wall_path)
		free(cub->map->n_wall_path);
	if (cub->map->e_wall_path)
		free(cub->map->e_wall_path);
	if (cub->map->s_wall_path)
		free(cub->map->s_wall_path);
	if (cub->map->w_wall_path)
		free(cub->map->w_wall_path);
	if (cub->map->map)
		free_p_to_p(cub->map->map);
	free(cub->map);
}

void	free_cub(t_cub *cub)
{
	if (cub->mini)
	{
		if (cub->mini->img)
			free(cub->mini->img);
		free(cub->mini);
	}
	if (cub->player)
		free(cub->player);
	if (cub->map)
		free_map(cub);
	if (cub->images)
		free_images(cub);
	if (cub->mlx)
		free(cub->mlx);
	free(cub);
}
