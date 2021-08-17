/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:44:41 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/08 15:12:23 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "includes/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_data {
	void			*img;
	int				*adres;
	int				pix_bit;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}					t_data;

typedef struct		s_tar {
	void			*mlx;
	void			*win;
	double			player_pos_x;
	double			player_pos_y;
	double			viev_x;
	double			viev_y;
	double			plane_x;
	double			plane_y;
	int				keycode;
	int				texture[5][4096];
	float			*array_wall_dist;
	int				button_a;
	int				button_w;
	int				button_s;
	int				button_d;
	int				button_esc;
	int				button_q;
	int				button_e;
	int				button_esk;
	int				**use_map_in_prog;
	int				wdt_map;
	int				hgt_map;
	int				screen;
	int				fd;
	int				player_position;
	int				wdt_win;
	int				hgt_win;
	int				floor;
	int				ceilling;
	char			texture_path[5][100];
	int				numsprites;
	double			**sprite;
	unsigned char	bmp_data[54];
	int				bmp_data_size;
	t_data			img;
}					t_tar;

typedef struct		s_make {
	int				each_ray;
	double			x_pos_on_screen;
	double			each_ray_pos_x;
	double			each_ray_pos_y;
	int				tmp_pos_x;
	int				tmp_pos_y;
	double			dist_to_side_x;
	double			dist_to_side_y;
	double			mod_ray_dist_x;
	double			mod_ray_dist_y;
	double			player_dist_to_wall;
	int				move_map_x;
	int				move_map_y;
	int				ray_wall_hit;
	int				wall_side;
	int				len_make_line;
	int				start_fill_pos;
	int				end_fill_pos;
	double			ray_wall_hit_pos;
	int				pix_tex_x;
	int				pix_tex_y;
	double			step;
	double			pix_tex_pos;
	int				each_spr;
	double			spr_cam_pos_x;
	double			spr_cam_pos_y;
	double			multiply_factor;
	double			factor_spr_wdt;
	double			factor_spr_hgt;
	int				spr_cam_place;
	int				spr_hgt;
	int				start_fill_spr_y;
	int				end_fill_spr_y;
	int				spr_wdt;
	int				start_fill_spr_x;
	int				end_fill_spr_x;
	int				color;
	int				fill_y;
	int				fill_x;
	int				corret_tex_spr_pos;
	int				i;
	int				test_dist;
}					t_make;

typedef struct		s_map_flag_args {
	int				resol;
	int				north;
	int				south;
	int				west;
	int				east;
	int				spr;
	int				floor;
	int				cell;
	int				player_position;
}					t_map_flag_args;

typedef struct		s_map_xy {
	int				x_i;
	int				y_j;
}					t_map_xy;
/*
** image **
*/
int					ft_make_image_on_screen(t_tar *tar);
/*
** calc and make image param (floor, wall, cell) **
*/
void				ft_image_calk(t_make *make, t_tar *tar);
void				ft_assigment_ray_variables(t_make *make);
void				ft_make_values_ray_variable(t_make *make, t_tar *tar);
void				ft_make_move_map_x_for_dda(t_make *make, t_tar *tar);
void				ft_get_wall_side_and_player_dist_to_wall(t_make *make,
					t_tar *tar);
void				ft_get_fill_param(t_make *make, t_tar *tar);
void				ft_get_fill_pix_param(t_make *make, t_tar *tar);
/*
** calc and make sprite param (floor, wall, cell) **
*/
void				ft_spr_calk_and_make(t_make *make, t_tar *tar,
					int *spr_ord);
void				ft_assigment_sprite_variables(t_make *make);
void				ft_make_values_spr_variables(t_make *make, t_tar *tar);
void				ft_make_start_end_spr_pos(t_make *make, t_tar *tar);
void				ft_make_sprite_on_screen(t_make *make, t_tar *tar);
/*
** sprite quicksort **
*/
void				ft_my_sprite_quicksort(int *order, double *dist,
					int amount);
void				ft_body_quicksort(double *dist, int *order, int left,
					int right);
void				ft_swap(double *dist, int *order, int i, int j);
/*
** make_next_buff_frame **
*/
int					ft_make_next_frame(t_tar *tar);
/*
** make_line **
*/
void				make_line(t_data *data, t_tar *tar, t_make *make);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				ft_make_super_color(void *color);
void				ft_fill_wall_color_path_one(t_make *make, t_tar *tar,
					t_data *data);
void				ft_fill_wall_color_path_two(t_make *make, t_tar *tar,
					t_data *data);
/*
** texture_init **
*/
void				texture_init(t_tar *tar);
/*
** malloc_arrey_sprite_for_make_line **
*/
void				ft_sprite_arrey_malloc(t_tar *tar);
/*
** move **
*/
void				ft_player_move(t_tar *tar);
void				ft_step_left(t_tar *tar);
void				ft_step_right(t_tar *tar);
void				ft_step_forward_back(t_tar *tar);
void				ft_step_back(t_tar *tar);
void				ft_turn_right(t_tar *tar, double old_dir_x,
					double old_plane_x);
void				ft_turn_left(t_tar *tar, double old_dir_x,
					double old_plane_x);
/*
** key **
*/
int					use_button_keep(int key, t_tar *tar);
int					use_button_let_go(int key, t_tar *tar);
/*
** map & arguments **
*/
int					ft_check_num_arg(int argc, char **argv);
int					ft_check_first_arg(char *argv, int i);
int					ft_check_first_arg(char *argv, int i);
void				ft_check_initial_map_make_map(char *initial_map,
					t_tar *tar);
void				ft_resol_check(t_tar *tar, int *i, char *buf,
					t_map_flag_args *map_flag_args);
void				ft_north_path_check(t_tar *tar, int *i, char *buf,
					t_map_flag_args *map_flag_args);
void				ft_south_path_check(t_tar *tar, int *i, char *buf,
					t_map_flag_args *map_flag_args);
void				ft_west_path_check(t_tar *tar, int *i, char *buf,
					t_map_flag_args *map_flag_args);
void				ft_east_path_check(t_tar *tar, int *i, char *buf,
					t_map_flag_args *map_flag_args);
void				ft_sprite_path_check(t_tar *tar, int *i, char *buf,
					t_map_flag_args *map_flag_args);
void				ft_floor_color_check(t_tar *tar, int *i, char *buf,
					t_map_flag_args *map_flag_args);
void				ft_celling_color_check(t_tar *tar, int *i, char *buf,
					t_map_flag_args *map_flag_args);
char				**ft_check_all_map(t_tar *tar, char *buf,
					t_map_flag_args *map_flag_args);
void				ft_assigment_map_flags_args(t_map_flag_args *map_flag_args,
					t_tar *tar);
char				*ft_buff_prepering(char *initial_map);
void				ft_check_map_len(t_tar *tar, char **tmp_map, int *i,
					int *max_map_len);
void				check_valid_map(t_tar *tar, char **tmp_map, int x, int y);
void				check_flag(t_map_flag_args *map_flag_args, t_tar *tar,
					char **tmap);
void				ft_free_tmp_variables(char **tmp_map);
void				ft_make_int_map(t_tar *tar, char **tmp_map);
void				ft_map_malloc(t_tar *tar, int *i, int max_map_len,
					char **tmap);
int					check_direction_view(t_tar *tar, char tmp_map);
void				ft_make_player_pos(t_tar *tar, char **tmp_map, int x,
					int y);
void				ft_make_spr_pos(t_tar *tar, int i, int j, int *sprite_num);
void				ft_zero_sprite(t_tar *tar, int *sprite_num);
void				make_sprite_number(t_tar *tar, char **tmp_map,
					char *tmp_buf);
void				ft_close_not_valid_map_free(t_tar *tar, char **tmap);
/*
** preparing variables **
*/
void				ft_assigment_tar_variables(t_tar *tar);
/*
** resolution mlx_get_screen_size **
*/
void				ft_check_resol(t_tar *tar);
/*
** screenshot **
*/
int					make_screenshot(t_tar *tar);
/*
** exit correct **
*/
int					ft_correct_exit_program(t_tar *tar, int arg);
/*
** libft function **
*/
int					ft_isdigit(int c);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strjoin(char *s1, char const *s2);
int					ft_strlen_mod(const char *s);

#endif
