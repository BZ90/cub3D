/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:01:25 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/16 09:18:23 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	append_to_map(t_cub *cub, char *str)
{
	char	**new_map;
	int		i;

	if (!str)
		return ;
	i = p_to_p_len(cub->map->map);
	new_map = malloc(sizeof(char *) * (i + 2));
	new_map[i] = ft_strdup(str);
	new_map[i + 1] = NULL;
	while (--i >= 0 && cub->map->map)
		new_map[i] = cub->map->map[i];
	if (cub->map->map)
		free(cub->map->map);
	cub->map->map = new_map;
}

void	remove_newlines_util(t_map *map, int i, char *buf)
{
	while (map->map[i])
	{
		if (map->map[i][ft_strlen(map->map[i]) - 1] == '\n')
		{
			buf = ft_substr(map->map[i], 0, ft_strlen(map->map[i]) - 1);
			free(map->map[i]);
			map->map[i] = buf;
		}
		++i;
	}
}

int	remove_newlines(t_map *map)
{
	char	*buf;
	int		i;

	if (map->n_wall_path == NULL || map->e_wall_path == NULL || \
	map->s_wall_path == NULL || map->w_wall_path == NULL || map->map == NULL)
		return (-1);
	buf = ft_substr(map->n_wall_path, 0, ft_strlen(map->n_wall_path) - 1);
	free(map->n_wall_path);
	map->n_wall_path = buf;
	buf = ft_substr(map->e_wall_path, 0, ft_strlen(map->e_wall_path) - 1);
	free(map->e_wall_path);
	map->e_wall_path = buf;
	buf = ft_substr(map->w_wall_path, 0, ft_strlen(map->w_wall_path) - 1);
	free(map->w_wall_path);
	map->w_wall_path = buf;
	buf = ft_substr(map->s_wall_path, 0, ft_strlen(map->s_wall_path) - 1);
	free(map->s_wall_path);
	map->s_wall_path = buf;
	i = 0;
	remove_newlines_util(map, i, buf);
	return (0);
}

void	pad_string(char **map, int index, int target_width, char filler)
{
	char	*new_string;
	int		i;

	if (target_width < (int)ft_strlen(map[index]))
		return ;
	new_string = malloc(sizeof(char) * (target_width + 1));
	i = 0;
	while (map[index][i])
	{
		new_string[i] = map[index][i];
		++i;
	}
	while (i < target_width)
	{
		new_string[i] = filler;
		++i;
	}
	new_string[i] = '\0';
	free(map[index]);
	map[index] = new_string;
}

void	make_even_width(t_map *map)
{
	int	widest;
	int	y;

	y = 0;
	widest = 0;
	while (map->map[y])
	{
		if ((int)ft_strlen(map->map[y]) > widest)
			widest = ft_strlen(map->map[y]);
		++y;
	}
	y = 0;
	while (map->map[y])
	{
		if ((int)ft_strlen(map->map[y]) < widest)
			pad_string(map->map, y, widest, ' ');
		++y;
	}
}
