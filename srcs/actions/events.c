/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <jtanner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:57:07 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/09 15:51:26 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	rotater(t_cub *cub)
{
	if (cub->player->mouse_r)
	{
		cub->player->direction.angle += cub->player->rot_spd * \
		cub->player->mouse_r;
		cub->player->mouse_r = 0;
	}
	else
		cub->player->direction.angle += cub->player->rot_spd;
	if (cub->player->direction.angle > 2 * PI)
		cub->player->direction.angle = 0;
	cub->player->direction.x = cos(cub->player->direction.angle);
	cub->player->direction.y = sin(cub->player->direction.angle);
	cub->player->mouse_r = false;
}

int	shutdown(t_cub *cub)
{
	destroy_images(cub);
	mlx_clear_window(cub->mlx->mlxptr, cub->mlx->winptr);
	mlx_destroy_window(cub->mlx->mlxptr, cub->mlx->winptr);
	cub->exiting = true;
	pthread_join(cub->ani_thread, NULL);
	free_cub(cub);
	exit(0);
}

int	loop(t_cub *cub)
{
	cast_rays(cub);
	print_map(cub->mini);
	movements(cub);
	return (0);
}

void	events(t_cub *cub)
{
	mlx_hook(cub->mlx->winptr, 6, 0, mouse_move, cub);
	mlx_hook(cub->mlx->winptr, 3, 0, key_release, cub);
	mlx_hook(cub->mlx->winptr, 2, 0, key_press, cub);
	mlx_hook(cub->mlx->winptr, 17, 0, shutdown, cub);
	mlx_loop_hook(cub->mlx->mlxptr, loop, cub);
	if (pthread_create(&cub->ani_thread, NULL, &animate, cub) != 0)
		exit(5);
}
