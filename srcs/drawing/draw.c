/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:54:33 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/09 10:56:00 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	pix_put(int x, int y, int color, t_cub	*cub)
{
	char	*pixel;
	int		i;

	i = cub->images->main_image->bits_per_pixel - 8;
	pixel = cub->mlx->img_data + (y * cub->images->main_image->line_size \
		+ x * (cub->images->main_image->bits_per_pixel / 8));
	*(int *)pixel = color;
	while (i >= 0)
	{
		if (cub->images->main_image->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> \
				(cub->images->main_image->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	findcolor(int h, int x, int y, t_image *img)
{
	double	d;
	char	*dst;

	d = h / (double)img->height;
	y = (int)y / d;
	dst = img->address + ((y * img->line_size) + \
		(x * (img->bits_per_pixel / 8)));
	return (*(unsigned int *)dst);
}

void	put_image_line(t_cub *cub, t_ray *ray)
{
	int	h;
	int	y;
	int	t;
	int	b;

	y = 0;
	h = (int)ray->wall_height;
	t = (HEIGHT / 2) + (h / 2);
	b = (HEIGHT / 2) - (h / 2);
	while (y < HEIGHT)
	{
		if (y >= b && y <= HEIGHT / 2)
			pix_put(ray->cur_ray, y, findcolor(h, \
				ray->texture_x, y - b, ray->texture), cub);
		else if (y < t && y > HEIGHT / 2)
			pix_put(ray->cur_ray, y, findcolor(h, \
				ray->texture_x, y - b, ray->texture), cub);
		else if (y > b)
			pix_put(ray->cur_ray, y, cub->map->ceiling, cub);
		else
			pix_put(ray->cur_ray, y, cub->map->floor, cub);
		y++;
	}
}
