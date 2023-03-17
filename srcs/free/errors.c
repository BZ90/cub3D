/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:56:55 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/10 09:29:56 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	map_error(t_cub *cub)
{
	mlx_destroy_window(cub->mlx->mlxptr, cub->mlx->winptr);
	destroy_images(cub);
	free_cub(cub);
	exit(MAP_ERROR);
}

void	image_error(t_cub *cub)
{
	mlx_destroy_window(cub->mlx->mlxptr, cub->mlx->winptr);
	destroy_images(cub);
	free_cub(cub);
	ft_fprintf(2, "Error: images\n");
	exit(3);
}

void	is_cub_error(char **argv)
{
	int	i;

	i = ft_strlen(argv[1]);
	i -= 4;
	if (ft_strncmp(argv[1] + i, ".cub", 4) != 0)
	{
		ft_fprintf(2, "Error: '%s' is not a cub file\n", argv[1]);
		exit (4);
	}
}
