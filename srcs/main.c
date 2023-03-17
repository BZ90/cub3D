/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:53:06 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/10 10:56:19 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
	{
		ft_fprintf(2, "Error: Invalid argument count.\n\
Correct usage: ./cub3d 'path_to_map'\n");
		return (1);
	}
	is_cub_error(argv);
	cub = malloc(sizeof(t_cub));
	initialize_cub(cub);
	parse_map(cub, argv[1]);
	init_minimap(cub);
	if (map_errors(cub->map, 0, 0))
		map_error(cub);
	if (get_images(cub) == -1)
		image_error(cub);
	events(cub);
	mlx_loop(cub->mlx->mlxptr);
	return (0);
}
