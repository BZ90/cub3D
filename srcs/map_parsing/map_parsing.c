/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:59:18 by jtanner           #+#    #+#             */
/*   Updated: 2023/03/16 09:18:38 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	get_map(t_cub *cub, int map_fd, char *line)
{
	while (line)
	{
		if (is_only_valid_map_chars(line))
			append_to_map(cub, line);
		else
			break ;
		free(line);
		line = get_next_line(map_fd);
	}
	if (line)
		free(line);
}

int	use_line_n_s(t_cub *cub, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		if (cub->map->n_wall_path == NULL)
			cub->map->n_wall_path = ft_strdup(&line[skip_identifier(line)]);
		else
			cub->map->duplicate_key = true;
		return (-1);
	}
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		if (cub->map->s_wall_path == NULL)
			cub->map->s_wall_path = ft_strdup(&line[skip_identifier(line)]);
		else
			cub->map->duplicate_key = true;
		return (-1);
	}
	return (0);
}

int	use_line(t_cub *cub, char *line)
{
	if (use_line_n_s(cub, line) == -1)
		return (0);
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		if (cub->map->w_wall_path == NULL)
			cub->map->w_wall_path = ft_strdup(&line[skip_identifier(line)]);
		else
			cub->map->duplicate_key = true;
		return (0);
	}
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		if (cub->map->e_wall_path == NULL)
			cub->map->e_wall_path = ft_strdup(&line[skip_identifier(line)]);
		else
			cub->map->duplicate_key = true;
		return (0);
	}
	else if (line[0] == 'F' && line[1] == ' ')
		return (get_colour(cub, line, 0));
	else if (line[0] == 'C' && line[1] == ' ')
		return (get_colour(cub, line, 1));
	else if ((line[0] == ' ' && ft_isinstring(line, '1')) || line[0] == '1')
		return (1);
	return (-1);
}

void	parse_lines(t_cub *cub, int map_fd)
{
	int		use_line_ret;
	char	*line;

	line = get_next_line(map_fd);
	while (line)
	{
		if (line[0] == '\n')
			free(line);
		else
		{
			use_line_ret = use_line(cub, line);
			if (use_line_ret)
				if (up_to_map(cub, line, use_line_ret, map_fd) == 2)
					break ;
			free(line);
		}
		line = get_next_line(map_fd);
	}
}

void	parse_map(t_cub *cub, char *map_path)
{
	int		map_fd;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
	{
		perror("Error: open");
		return ;
	}
	parse_lines(cub, map_fd);
	close(map_fd);
	if (!cub->map->map)
		return ;
	remove_newlines(cub->map);
	make_even_width(cub->map);
	cub->map->width = ft_strlen(cub->map->map[0]);
	cub->map->height = p_to_p_len(cub->map->map);
	get_player_start_direction(cub);
}
