/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:46:35 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/09 23:49:03 by tfiguero         ###   ########.fr       */
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

/*	defines	*/
# define MLX_ERROR		0
# define HEIGHT 		1080
# define WIDTH			1080

typedef	struct	s_player
{
	char	dir;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
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

typedef struct s_libx
{
	t_img	img;
	t_win	win;
}		t_libx;

typedef struct s_data
{
	t_map	*m;
	t_libx	*l;
}		t_data;



char	*get_next_line(int fd);
char	*ft_strjoin(char *ret, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_clean_buffer(char *data);
char	*ft_fill_data(char *data, int fd, int flag);
char	*ft_free(char **buffer);

/*	init.c	*/
void	ft_init_tdata(t_data *data);
void	ft_init_player_pos(t_player *p, int x, int y);

/*	parse_info.c	*/
void	ft_readfile(int fd, t_map *m, int j);
int		ft_check_file(char *map, t_map *m);
char	*ft_get_fc(char *str, char c);
int		ft_find_info(t_map *m, int j, int line_len, int dot_len);
int		ft_parse_info(t_map *m);
/*	parse_map.c	*/
void	ft_find_map_limits(t_map *m, int i);
char	*ft_get_map_line(char	*str, int width, int i, int j);
int		ft_get_map(t_map *m, int *i);
int		ft_check_valid_map(t_map *m, int i, int j, int player);
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