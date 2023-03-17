/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:30:23 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/09 14:01:59 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	key_press(int key, t_cub *cub)
{
	if (key == KEY_ANSI_W)
		cub->player->mv_fw = true;
	if (key == KEY_ANSI_S)
		cub->player->mv_bw = true;
	if (key == KEY_LEFT)
		cub->player->rot_l = true;
	if (key == KEY_RIGHT)
		cub->player->rot_r = true;
	if (key == KEY_ANSI_A)
		cub->player->mov_l = true;
	if (key == KEY_ANSI_D)
		cub->player->mov_r = true;
	if (key == KEY_ANSI_E)
		open_door(cub);
	if (key == KEY_ESCAPE)
		shutdown(cub);
	return (1);
}

int	key_release(int key, t_cub *cub)
{
	if (key == KEY_ANSI_W)
		cub->player->mv_fw = false;
	if (key == KEY_ANSI_S)
		cub->player->mv_bw = false;
	if (key == KEY_LEFT)
		cub->player->rot_l = false;
	if (key == KEY_RIGHT)
		cub->player->rot_r = false;
	if (key == KEY_ANSI_A)
		cub->player->mov_l = false;
	if (key == KEY_ANSI_D)
		cub->player->mov_r = false;
	return (1);
}

int	mouse_move(int x, int y, t_cub *cub)
{
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
	{
		if (y > HEIGHT || y < 0)
			cub->player->mx = 0;
		return (1);
	}
	if (cub->player->mx == 0)
		cub->player->mx = x;
	if (x < cub->player->mx)
		cub->player->mouse_l = (cub->player->mx - x) / 3;
	if (x > cub->player->mx)
		cub->player->mouse_r = (x - cub->player->mx) / 3;
	cub->player->mx = x;
	if (cub->player->mx > WIDTH)
		cub->player->mx = WIDTH;
	if (cub->player->mx < 0)
		cub->player->mx = 0;
	return (1);
}
