/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:03:29 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/16 10:29:58 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	img_pix_put(int x, int y, int color, t_td	*test)
{
	char	*pixel;
	int		i;

	i = test->img->bits_per_pixel - 8;
	pixel = test->img->address + (y * test->img->line_size + x * \
	(test->img->bits_per_pixel / 8));
	*(int *)pixel = color;
	while (i >= 0)
	{
		if (test->img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (test->img->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	putplayer(t_td	*test)
{
	int	x;
	int	y;

	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 3)
		{
			img_pix_put((test->player->x * test->cw) + x, \
			(test->player->y * test->ch) + y, 0xFF0000, test);
			y++;
		}
		x++;
	}
}

void	putsquare(t_td	*test, int x, int y)
{
	double	xx;
	double	yy;
	int		color;

	xx = x * test->cw;
	yy = y * test->ch;
	color = 0xffffff00;
	if (test->map->map[y][x] == '1' || test->map->map[y][x] == 'N')
		color = 0x000000;
	if (test->map->map[y][x] == 'D' || test->map->map[y][x] == 'o')
		color = 0xc06060;
	if (test->map->map[y][x] == 'd')
		color = 0x50a050;
	if (test->map->map[y][x] == '0')
		color = 0xFFFFFF;
	while (xx < ((x + 1) * test->cw))
	{
		yy = y * test->ch;
		while (yy < ((y + 1) * test->ch))
		{
			img_pix_put(xx, yy, color, test);
			yy++;
		}
		xx++;
	}
}

void	setback(t_td *test)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (HEIGHT / 6))
	{
		j = 0;
		while (j < (WIDTH / 6))
			img_pix_put(j++, i, 0xffffff00, test);
		i++;
	}
}

void	print_map(t_td	*test)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	test->cw = (WIDTH / 6) / test->map->width;
	test->ch = (HEIGHT / 6) / test->map->height;
	setback(test);
	while (x < test->map->width)
	{
		y = 0;
		while (y < test->map->height)
		{
			putsquare(test, x, y);
			y++;
		}
		x++;
	}
	putplayer(test);
	mlx_put_image_to_window(test->mlx->mlxptr, test->mlx->winptr, \
	test->img->img_ptr, \
	WIDTH - (WIDTH / 6), HEIGHT - (HEIGHT / 6));
}
