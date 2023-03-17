/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_get_colours_util.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:29:22 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/16 09:00:06 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	get_colour_initial(t_cub *cub, int where)
{
	if (where == 0 && cub->map->did_floor == true)
		cub->map->colour_error = true;
	if (where == 1 && cub->map->did_ceil == true)
		cub->map->colour_error = true;
	if (where == 0 && cub->map->did_floor == false)
		cub->map->did_floor = true;
	if (where == 1 && cub->map->did_ceil == false)
		cub->map->did_ceil = true;
}

void	set_colour(t_cub *cub, int colour[3], int where, char ***colour_values)
{
	free_p_to_p(*colour_values);
	if (where == 1)
		cub->map->floor = (colour[0] << 16 | colour[1] << 8 | colour[2]);
	else if (where == 0)
		cub->map->ceiling = (colour[0] << 16 | colour[1] << 8 | colour[2]);
}

int	get_colour(t_cub *cub, char *line, int where)
{
	char		**colour_values;
	int			colour[3];
	int			i;

	get_colour_initial(cub, where);
	colour_values = ft_split(&line[skip_identifier(line)], ',');
	if (p_to_p_len(colour_values) != 3)
	{
		free_p_to_p(colour_values);
		cub->map->colour_error = true;
		return (0);
	}
	i = -1;
	while (++i < 3)
	{
		colour[i] = ft_atoi(colour_values[i]);
		if (colour[i] > 255 || colour[i] < 0)
		{
			free_p_to_p(colour_values);
			cub->map->colour_error = true;
			return (0);
		}
	}
	set_colour(cub, colour, where, &colour_values);
	return (0);
}
