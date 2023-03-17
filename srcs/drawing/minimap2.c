/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:08:45 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/16 11:01:20 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	minimap_image(t_td *map)
{
	map->img->img_ptr = mlx_new_image(map->mlx->mlxptr, WIDTH / 6, HEIGHT / 6);
	map->img->address = mlx_get_data_addr(map->img->img_ptr, \
	&map->img->bits_per_pixel, &map->img->line_size, &map->img->endian);
}
