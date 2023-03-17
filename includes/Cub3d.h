/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <bzawko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:05:09 by bzawko            #+#    #+#             */
/*   Updated: 2023/03/16 11:09:12 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*		Definitions				*/
# define MAP_ERROR 2
# define HEIGHT 720
# define WIDTH  1080
# define PI 3.14159265

/*		Library includes		*/
# include "libft.h"
# include "keys.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

/*		Structures				*/

/* Declarations */
typedef struct s_mlx	t_mlx;
typedef struct s_cub	t_cub;
typedef struct s_image	t_image;

/* Definitions */
typedef struct s_dvector
{
	double	x;
	double	y;
	double	angle;
}			t_dvector;

typedef struct s_map_err
{
	bool	valid_space;
	bool	valid_wall;
	bool	valid_other;
	int		player_count;
}			t_map_err;

typedef struct s_ray
{
	double	wall_dist;
	double	wall_x;
	double	wall_height;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	int		cur_ray;
	int		ray_x;
	int		ray_y;
	int		step_x;
	int		step_y;
	int		texture_x;
	bool	hit;
	bool	side;
	int		door;
	t_image	*texture;
}			t_ray;

typedef struct s_player
{
	int			health;
	int			ammo;
	double		x;
	double		y;
	int			mx;
	int			mouse_r;
	int			mouse_l;
	bool		rot_l;
	bool		rot_r;
	bool		mv_fw;
	bool		mv_bw;
	bool		mov_r;
	bool		mov_l;
	double		mv_spd;
	double		rot_spd;
	t_dvector	direction;
	t_cub		*back;
}			t_player;

typedef struct s_map
{
	char	*s_wall_path;
	char	*n_wall_path;
	char	*e_wall_path;
	char	*w_wall_path;
	int		floor;
	int		ceiling;
	bool	did_floor;
	bool	did_ceil;
	char	**map;
	int		height;
	int		width;
	bool	colour_error;
	bool	invalid_key;
	bool	duplicate_key;
	t_cub	*back;
}			t_map;

typedef struct s_image
{
	void	*img_ptr;
	char	*address;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	t_mlx	*mlx;
}			t_image;

typedef struct s_images
{
	t_mlx	*mlx;
	t_image	*door1;
	t_image	*door2;
	t_image	*door3;
	t_image	*door4;
	t_image	*door5;
	t_image	*door6;
	t_image	*door7;
	t_image	*s_wall;
	t_image	*n_wall;
	t_image	*e_wall;
	t_image	*w_wall;
	t_image	*curdoor;
	t_image	*main_image;
}			t_images;

typedef struct s_mlx
{
	void	*mlxptr;
	void	*winptr;
	void	*image;
	char	*img_data;

}			t_mlx;

typedef struct s_td
{
	t_image		*img;
	t_mlx		*mlx;
	t_map		*map;
	t_player	*player;
	double		cw;
	double		ch;
}			t_td;

struct s_cub
{
	t_player	*player;
	t_map		*map;
	t_images	*images;
	t_mlx		*mlx;
	t_td		*mini;
	pthread_t	ani_thread;
	bool		exiting;
};

/*		Function prototypes		*/

/* Init/Malloc Functions */
void	init_player(t_player *cub);
void	t_mlx_init(t_mlx *cub);
void	init_main_image(t_image *cub, t_mlx *m);
void	init_images(t_images *cub);
void	initialize_cub(t_cub *cub);
void	init_map(t_map *cub);
void	init_minimap(t_cub *cub);
void	init_ray_data_utils(t_cub *cub, t_ray *ray_data);
void	set_images_null(t_images *cub);
void	minimap_image(t_td *map);

/* Free functions */
void	free_p_to_p(char **ptp);
void	free_cub(t_cub *cub);
void	destroy_images(t_cub *cub);
int		shutdown(t_cub *cub);
void	free_and_exit(t_cub *cub, char *line);

/* Parse functions */
void	parse_map(t_cub *cub, char *map_path);
void	pad_string(char **map, int index, int target_width, char filler);
void	make_even_width(t_map *map);
int		main(int argc, char **argv);
int		get_images(t_cub *cub);
void	initialize_cub(t_cub *cub);
void	parse_map(t_cub *cub, char *map_path);
void	initialize_mlx(t_cub *cub);
void	draw_images(t_cub *cub);
void	free_cub(t_cub *cub);
void	get_player_start_direction(t_cub *cub);
void	append_to_map(t_cub *cub, char *str);
int		skip_identifier(char *line);
int		get_colour(t_cub *cub, char *line, int where);
int		use_line_n_s(t_cub *cub, char *line);
int		use_line(t_cub *cub, char *line);
int		remove_newlines(t_map *map);
void	get_map(t_cub *cub, int map_fd, char *line);
void	set_direction(t_cub *cub, char c);
void	parse_lines(t_cub *cub, int map_fd);
void	remove_newlines_util(t_map *map, int i, char *buf);
int		up_to_map(t_cub *cub, char *line, int use_line_ret, int map_fd);

/* Map Functions */
bool	is_valid_space(t_map *map, int y, int x);
bool	is_valid_tile(t_map *map, int y, int x);
bool	is_valid_wall(t_map *map, int y, int x);
bool	is_out_char(char c);
bool	is_only_valid_map_chars(char *line);
void	get_colour_initial(t_cub *cub, int where);
void	set_colour(t_cub *cub, int colour[3], int where, char ***colour_values);

/* Error functions */
void	image_error(t_cub *cub);
int		map_errors(t_map *map, int i, int j);
bool	is_valid_wall_utily(t_map *map, int x, int y);
bool	is_valid_wall_utily1(t_map *map, int x, int y);
bool	is_valid_wall_utilx(t_map *map, int x, int y);
bool	is_valid_wall_utilx1(t_map *map, int x, int y);
bool	is_valid_wall_util(t_map *map, int x, int y);
bool	is_valid_space_utily(t_map *map, int y, int x);
bool	is_valid_space_utily1(t_map *map, int y, int x);
bool	is_valid_space_utilx(t_map *map, int y, int x);
bool	is_valid_space_utilx1(t_map *map, int y, int x);
bool	is_out_char(char c);
bool	is_error(t_map_err m);
int		initial_error(t_map *map);
void	init_map_err(t_map_err *m);
int		check_error(t_map *map, t_map_err *m, int i, int j);
void	map_error(t_cub *cub);
void	is_cub_error(char **argv);

/* Ray Functions */
int		cast_rays(t_cub *cub);
void	ray_cast_ifelse(t_cub *cub, t_ray *ray_data);

/* Draw Functions */
void	put_image_line(t_cub *cub, t_ray *ray);

/* Event Functions */
int		key_press(int key, t_cub *cub);
int		key_release(int key, t_cub *cub);
int		mouse_move(int x, int y, t_cub *cub);
void	events(t_cub *cub);
void	movements(t_cub *cub);
void	rotate(t_cub *cub);
void	rotater(t_cub *cub);

/* Miscellaneous functions */
int		p_to_p_len(char **ptp);
void	print_map(t_td	*test);

/* Doors */
void	set_door_open(char **map);
void	open_door(t_cub *cub);
bool	opening_door(char **map);
int		init_doors(t_cub *cub);
void	*animate(void *arg);

#endif
