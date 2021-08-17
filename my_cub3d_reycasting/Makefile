NAME =	cub3D

INCLUDE = cub3d.h

SRC =		main.c \
			assigments_option/ft_assigments_tar_variables.c \
			assigments_option/use_button.c \
			assigments_option/texture_preparing.c \
			assigments_option/check_resol.c \
			make_screenshot/make_screenshot.c \
			check_map_and_param/ft_check_initial_map_make_map.c \
			check_map_and_param/ft_check_all_map.c \
			check_map_and_param/ft_resol_check.c \
			check_map_and_param/ft_north_path_check.c \
			check_map_and_param/ft_south_path_check.c \
			check_map_and_param/ft_west_path_check.c \
			check_map_and_param/ft_east_path_check.c \
			check_map_and_param/ft_sprite_path_check.c \
			check_map_and_param/ft_floor_color_check.c \
			check_map_and_param/ft_celling_color_check.c \
			check_map_and_param/ft_check_num_arg.c\
			check_map_and_param/check_valid_map/ft_buff_preparing.c \
			check_map_and_param/check_valid_map/ft_char_map_preparig.c \
			check_map_and_param/check_valid_map/ft_check_valid_map.c \
			check_map_and_param/check_valid_map/ft_ending_preparing.c\
			check_map_and_param/check_valid_map/ft_make_int_map.c \
			check_map_and_param/check_valid_map/ft_make_player_direction.c \
			check_map_and_param/check_valid_map/ft_make_player_position.c \
			check_map_and_param/check_valid_map/ft_make_sprite_position.c \
			check_map_and_param/check_valid_map/ft_sprite_preparig.c \
			general/ft_spr_calk_and_make.c \
			general/ft_image_calk.c \
			general/ft_image_calk_continue.c \
			general/ft_make_image_on_screen.c \
			general/make_next_frame.c \
			general/make_line.c \
			general/ft_my_sprite_quicksort.c \
			general/make_color.c \
			move_options/ft_player_move.c \
			move_options/ft_step_right.c \
			move_options/ft_step_left.c \
			move_options/ft_turn_player.c \
			small_part_libft/ft_isdigit.c \
			small_part_libft/ft_split.c \
			small_part_libft/ft_strdup.c\
			small_part_libft/ft_substr.c \
			small_part_libft/ft_strlen.c \
			small_part_libft/ft_atoi.c \
			small_part_libft/ft_memcmp.c \
			small_part_libft/ft_strjoin.c\

OBJ_NAME	= $(SRC:.c=.o)

CC			= gcc -g -Wall -Wextra -Werror

RM			= rm -f

LIBX		= includes/libmlx.a -framework OpenGL -framework AppKit

$(NAME):	$(OBJ_NAME)
			$(CC) -o $(NAME) $(OBJ_NAME) $(LIBX)

bonus:		$(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJ_NAME) 

fclean:		clean
			$(RM) ${NAME} 

re:			fclean all