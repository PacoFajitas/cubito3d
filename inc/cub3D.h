/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:46:35 by tfiguero          #+#    #+#             */
/*   Updated: 2024/04/07 21:07:10 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_gen
{
	char	**file;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	int		height;
	int		width;
}				t_map;

char	*get_next_line(int fd);
char	*ft_strjoin(char *ret, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_clean_buffer(char *data);
char	*ft_fill_data(char *data, int fd, int flag);
char	*ft_free(char **buffer);
/*	print_utils.c	*/
void 	ft_print_array(char **array, int i);
void	ft_print_map_data(t_map *m);
#endif