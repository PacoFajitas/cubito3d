/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:46:35 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/30 21:56:26 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

/*	libraries	*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "mlx/mlx.h"
# include "keys.h"

/*	defines	*/
# define MLX_ERROR		0

# define HEIGHT 		1080
# define WIDTH			1080

# define MOVESPEED		0.0125
# define ROTSPEED		0.015

# define NORTH			0
# define SOUTH			1
# define EAST			2
# define WEST			3

# define TEX_SIZE		64

// falta un int mapX, mapY que no se si hace falta
typedef struct s_ray
{
	double	cameraX;
	double	dirX;
	double	dirY;
	double	deltaX;
	double	deltaY;
	double	sideX;
	double	sideY;
	double	wall_dist;
	double	wallX;
	int		side;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		lineH;
	int		draw_start;
	int		draw_end;
}		t_ray;

typedef	struct	s_player
{
	char	dir;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		rotate;
	int		move_x;
	int		move_y;
	int		has_moved;
}		t_player;


typedef struct s_map
{
	char		**file;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	int			f_rgb[3];
	int			c_rgb[3];
	char		**map;
	int			height;
	int			width;
	t_player	*p;
}				t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_tex
{
	int				index;
	int				x;
	int				y;
	double			step;
	double			pos;
	unsigned long	hex_cel;
	unsigned long	hex_floor;
	int				height;
	int				width;
}	t_tex;

// typedef struct s_text
// {
// 	void	*img;
// 	char	*addr;
// 	int		bpp;
// 	int		line_len;
// 	int		endian;
// 	int		width;
// 	int		height;
// }	t_text;


typedef struct s_data
{
	t_player	*p;
	t_map		*m;
	void		*mlx;
	void		*win;
	t_ray		r;
	t_img		img;
	t_img		text_img[4];
	t_tex		t;
	int			**text;
	int			**text_pixel;
	int			height;
	int			width;
}		t_data;


void	init_texture_img(t_data *data, t_img *image, char *path);
void	put_pixel(t_img *data, int x, int y, int color);
int		*xpm_to_img(t_data *data, char *path);
char	*get_next_line(int fd);
char	*ft_strjoin(char *ret, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_clean_buffer(char *data);
char	*ft_fill_data(char *data, int fd, int flag);
char	*ft_free(char **buffer);

/*	INIT	*/
/*	init_data.c	*/
void	ft_init_player(t_player *p);
void	ft_init_map(t_data *data, t_map *m);
void	ft_init_tray(t_ray *r);
void	ft_init_tdata(t_data *data);
/*	init_mlx.c	*/
void	ft_init_start_img(t_img *img);
void	ft_init_img(t_data *data, t_img *img);
void	ft_init_mlx(t_data *data);
/*	init_textures.c	*/
void	ft_init_ttex(t_tex *t);
void	ft_init_text_pixel(t_data *data);
/*	MOVEMENT	*/
/*	input_handler.c	*/
int		ft_key_pressed(int key, t_data *data);
int		ft_key_released(int key, t_data *data);
void	listen_for_input(t_data *data);
/*	player_direction.c	*/
void	ft_init_player_pos(t_player *p, int x, int y, char c);
void	ft_init_player_dir(t_player *p);
/*	player_movement.c	*/
int		ft_move_player_up(t_data *data);
int		ft_move_player_down(t_data *data);
int		ft_move_player_left(t_data *data);
int		ft_move_player_right(t_data *data);
int		ft_move_player(t_data *data);
/*	player_position.c	*/
int		ft_valid_pos(t_data *data, double newX, double newY);
int		ft_validate_move(t_data *data, double newX, double newY);
/*	player_rotate.c	*/
int	ft_rotate_lr(t_data *data);
int	ft_rotate_player(t_data *data);

/*	PARSE	*/
/*	parse_info.c	*/
void	ft_readfile(int fd, t_map *m, int j);
int		ft_check_file(char *map, t_map *m);
char	*ft_get_fc(char *str, char c);
int		ft_find_info(t_map *m, int j, int line_len);
int		ft_parse_info(t_map *m);
/*	parse_info2.c	*/
int		ft_check_rgb(t_map *m);
int		ft_check_texts(t_map *m);
/*	parse_map.c	*/
void	ft_find_map_limits(t_map *m, int i);
char	*ft_get_map_line(char	*str, int width, int i, int j);
int		ft_get_map(t_map *m, int *i);
int		ft_check_valid_map(t_map *m, int i, int j, int player);
/*	parse_textures.c	*/
int	ft_check_textures(t_data *data, t_tex *t);

/*	RENDER	*/
/*	raycast.c	*/
void	ft_init_raycast(t_ray *r, t_player *p, int x);
void	ft_set_dda(t_ray *r, t_player *p);
void	ft_perform_dda(t_map *m, t_ray *r);
void	ft_calculate_length(t_data *data, t_ray *r);
int		ft_raycasting(t_data *data);
/*	render.c	*/
void	ft_set_image_pixel(t_img *image, int x, int y, int color);
void	ft_set_frame_image_pixel(t_data *data, t_img *img, int x, int y);
void	ft_render_frame(t_data *data);
void	ft_render_raycast(t_data *data);
int		ft_render(t_data *data);
/*	textures.c	*/
void	ft_get_texture_index(t_data *data, t_ray *r);
void	ft_update_texture_pixels(t_data *data, t_tex *t, t_ray *r, int x);

/*	UTILS	*/
/*	errors.c	*/
void	ft_free_array(void **array);
void	ft_free_tmap(t_map *m);
void	ft_error(t_data *data, char *msg);
/*	print_utils.c	*/
void 	ft_print_array(char **array, int i);
void	ft_print_map_data(t_map *m);
/*	utils_line.c	*/
int		ft_count_lines(int fd);
char	*ft_put_spaces(int width);
char	*ft_trim_final_spaces(char *str, int j, int k);
char	*ft_clean_line(char *str);
/*	utils_tabs.c	*/
int		ft_count_tabs(char *line);
char	*ft_return_tabs_expanded(char *line, char *n_line);
char	*ft_expand_tabs(char *line);

#endif