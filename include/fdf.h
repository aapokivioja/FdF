/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 17:50:55 by akivioja      #+#    #+#                 */
/*   Updated: 2023/09/15 17:26:41 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define HEIGHT 1080
# define WIDTH 1920
# define MENU_WIDTH 250

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

// Motherfucker

typedef struct t_fdf
{
	int		width;
	int		height;
	int		**int_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	double	angle;
	int		max_value;
	int		min_value;

	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

typedef struct t_slope
{
	float	x;
	float	y;
	float	x1;
	float	y1;

	float	x_new;
	float	y_new;
	float	x1_new;
	float	y1_new;
}			t_slope;

void		parse(char *filename, t_fdf *data);
void		draw(t_fdf *data);
void		bresenham(t_slope *vs, t_fdf *data);
float		mod(float i);
int			max_num(int a, int b);
int			close_window(t_fdf *data);
int			get_height(char *filename);
int			get_width(char *filename);

#endif
