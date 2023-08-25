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

void	isometricV3(t_slope *sval, t_vs *vs, double angle, int onezero)
{
	if (onezero == 0)
	{
		sval -> x = (sval -> x - sval -> y) * cos(angle);
		sval -> y = (sval -> x + sval -> y) * sin(angle) - vs -> z;
	}
	if (onezero == 1)
	{
		sval -> x1 = (sval -> x1 - sval -> y1) * cos(angle);
		sval -> y1 = (sval -> x1 + sval -> y1) * sin(angle) - vs -> z1;
	}
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->int_matrix[(int)y][(int)x];
	z1 = data->int_matrix[(int)y1][(int)x1];
	// -- Zoom --
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	//  -- Color --
	if (z || z1)
		data->color = 0xffc0cb;
	else
		data->color = 0xffffff;
	// -- 3d --
	isometric(&x, &y, z, data->angle);
	isometric(&x1, &y1, z1, data->angle);
	// -- Key shifts --

	// Real
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	// Figure out how many steps to the left and down
	//from a point
	x_step = x1 - x;
	y_step = y1 - y;
	max = max_num(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	bresenhamV3(t_slope *sval, t_fdf *data)
{
	t_vs	*vs;
	int		xdif;
	int		ydif;

	vs = (t_vs *)malloc(sizeof(t_vs));
	vs -> z = data->int_matrix[(int)sval -> y][(int)sval -> x];
	vs -> z1 = data->int_matrix[(int)sval -> y1][(int)sval -> x1];
	// -- Zoom --
	sval -> x *= data->zoom;
	sval -> y *= data->zoom;
	sval -> x1 *= data->zoom;
	sval -> y1 *= data->zoom;
	//  -- Color --
	if (vs -> z || vs -> z1)
		data->color = 0xffc0cb;
	else
		data->color = 0xffffff;
	// -- 3d --
	isometricV3(sval, vs, data->angle, 0);
	isometricV3(sval, vs, data->angle, 1);
	// -- Key shifts --

	// Real
	sval -> x += data->shift_x;
	sval -> y += data->shift_y;
	sval -> x1 += data->shift_x;
	sval -> y1 += data->shift_y;
	// Figure out how many steps to the left and down
	//from a point
	vs -> x_step = sval -> x1 - sval -> x;
	vs -> y_step = sval -> y1 - sval -> y;
	vs -> max = max_num(mod(vs -> x_step), mod(vs -> y_step));
	vs -> x_step /= vs -> max;
	vs -> y_step /= vs -> max;
	xdif = (sval -> x - sval -> x1);
	ydif = (sval -> y - sval -> y1);
	while ( (int)xdif || (int)ydif)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, sval -> x, sval -> y, data->color);
		sval -> x += vs -> x_step;
		sval -> y += vs -> y_step;
		xdif = (sval -> x - sval -> x1);
		ydif = (sval -> y - sval -> y1);
	}
	free(vs);
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}


void	drawNew(t_fdf *data)
{
	t_slope	*sval;

	sval = (t_slope *)malloc(sizeof(t_slope));
	sval -> y = 0;
	while (sval -> y < data->height)
	{
		sval -> x = 0;
		while (sval -> x < data->width)
		{
			if (sval -> x < data->width - 1)
			{
				sval -> x1 = sval -> x + 1;
				sval -> y1 = sval -> y;
				bresenhamV3(sval, data);
			}
			if (sval -> y < data->height - 1)
			{
				sval -> x1 = sval -> x;
				sval -> y1 = sval -> y + 1;
				bresenhamV3(sval, data);
			}
			sval -> x++;
		}
		sval -> y++;
	}
	free(sval);
}
