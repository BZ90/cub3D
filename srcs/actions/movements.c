/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <jtanner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:20:55 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/09 15:53:27 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	rotate(t_cub *cub)
{
	if (cub->player->rot_l || cub->player->mouse_l)
	{
		if (cub->player->mouse_l)
		{
			cub->player->direction.angle -= cub->player->rot_spd * \
			cub->player->mouse_l;
			cub->player->mouse_l = 0;
		}
		else
			cub->player->direction.angle -= cub->player->rot_spd;
		if (cub->player->direction.angle < 0)
			cub->player->direction.angle = 2 * PI;
		cub->player->direction.x = cos(cub->player->direction.angle);
		cub->player->direction.y = sin(cub->player->direction.angle);
		cub->player->mouse_l = false;
	}
	if (cub->player->rot_r || cub->player->mouse_r)
		rotater(cub);
}

static bool	check_passable(char c)
{
	if (c == '1' || c == 'D' || c == 'o')
		return (false);
	else
		return (true);
}

static void	move_fw_bw(t_cub *cub)
{
	double	x;
	double	y;

	if (cub->player->mv_fw)
	{
		y = cub->player->y;
		x = cub->player->x;
		y += cub->player->direction.y * cub->player->mv_spd;
		x += cub->player->direction.x * cub->player->mv_spd;
		if (check_passable(cub->map->map[(int)y][(int)cub->player->x]))
			cub->player->y = y;
		if (check_passable(cub->map->map[(int)cub->player->y][(int)x]))
			cub->player->x = x;
	}
	if (cub->player->mv_bw)
	{
		y = cub->player->y;
		x = cub->player->x;
		y -= cub->player->direction.y * cub->player->mv_spd;
		x -= cub->player->direction.x * cub->player->mv_spd;
		if (check_passable(cub->map->map[(int)y][(int)cub->player->x]))
			cub->player->y = y;
		if (check_passable(cub->map->map[(int)cub->player->y][(int)x]))
			cub->player->x = x;
	}
}

static void	move_left_right(t_cub *cub, t_dvector side_dir)
{
	double	x;
	double	y;

	if (cub->player->mov_r)
	{
		y = cub->player->y;
		x = cub->player->x;
		y += side_dir.y * cub->player->mv_spd;
		x += side_dir.x * cub->player->mv_spd;
		if (check_passable(cub->map->map[(int)y][(int)cub->player->x]))
			cub->player->y = y;
		if (check_passable(cub->map->map[(int)cub->player->y][(int)x]))
			cub->player->x = x;
	}
	if (cub->player->mov_l)
	{
		y = cub->player->y;
		x = cub->player->x;
		y -= side_dir.y * cub->player->mv_spd;
		x -= side_dir.x * cub->player->mv_spd;
		if (check_passable(cub->map->map[(int)y][(int)cub->player->x]))
			cub->player->y = y;
		if (check_passable(cub->map->map[(int)cub->player->y][(int)x]))
			cub->player->x = x;
	}
}

void	movements(t_cub *cub)
{
	t_dvector	side_dir;

	rotate(cub);
	move_fw_bw(cub);
	if (cub->player->mov_l || cub->player->mov_r)
	{
		if (cub->player->direction.angle > PI * 1.5)
			side_dir.angle = cub->player->direction.angle - PI * 1.5;
		else
			side_dir.angle = cub->player->direction.angle + PI / 2;
		side_dir.x = cos(side_dir.angle);
		side_dir.y = sin(side_dir.angle);
		move_left_right(cub, side_dir);
	}
}
