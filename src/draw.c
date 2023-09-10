/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 16:32:22 by akivioja      #+#    #+#                 */
/*   Updated: 2023/08/25 17:46:55 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	max_num(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	isometric(float *x, float *y, int z, double angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

unsigned int	map_value_to_color(int value, int min, int max)
{
	int	red;
	int	blue;
	int	green;

	red = 255 - (255 * (value - min)) / (max - min);
	blue = (255 * (value - min)) / (max - min);
	green = 0;
	return ((red << 16) | (green << 8) | blue);
}

void	bresenham(t_slope *vs, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->int_matrix[(int)(vs->y)][(int)(vs->x)];
	z1 = data->int_matrix[(int)(vs->y1)][(int)(vs->x1)];
	vs->x_new = vs->x * data->zoom;
	vs->y_new = vs->y * data->zoom;
	vs->x1_new = vs->x1 * data->zoom;
	vs->y1_new = vs->y1 * data->zoom;
	if (z || z1)
		data->color = map_value_to_color(z, data->max_value, data->min_value);
	else
		data->color = 0xffffff;
	isometric(&(vs->x_new), &(vs->y_new), z, data->angle);
	isometric(&(vs->x1_new), &(vs->y1_new), z1, data->angle);
	vs->x_new = vs->x_new + data->shift_x;
	vs->y_new = vs->y_new + data->shift_y;
	vs->x1_new = vs->x1_new + data->shift_x;
	vs->y1_new = vs->y1_new + data->shift_y;
	x_step = vs->x1_new - vs->x_new;
	y_step = vs->y1_new - vs->y_new;
	max = max_num(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while (((int)(vs->x_new - vs->x1_new)) || ((int)(vs->y_new - vs->y1_new)))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, vs->x_new, vs->y_new,
			data->color);
		vs->x_new = vs->x_new + x_step;
		vs->y_new = vs->y_new + y_step;
	}
}

void	draw(t_fdf *data)
{
	t_slope	*vs;

	vs = NULL;
	vs = (t_slope *)malloc(sizeof(t_slope)); // Missing a malloc check here
	vs->y = 0;
	while (vs->y < data->height)
	{
		vs->x = 0;
		while (vs->x < data->width)
		{
			if (vs->x < data->width - 1)
				vs->x1 = vs->x + 1;
			vs->y1 = vs->y;
			bresenham(vs, data);
			if (vs->y < data->height - 1)
				vs->y1 = vs->y + 1;
			vs->x1 = vs->x;
			bresenham(vs, data);
			vs->x = vs->x + 1;
		}
		vs->y = vs->y + 1;
	}
}
