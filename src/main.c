/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 18:36:44 by akivioja      #+#    #+#                 */
/*   Updated: 2023/09/15 17:26:16 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_int_matrix(int **intmatrix, t_fdf *data)
{
	int	row;
	int	*current_row;
	int	h;

	row = 0;
	h = 0;
	current_row = intmatrix[row];
	while (h < data->height)
	{
		free(current_row);
		row++;
		current_row = intmatrix[row];
		h++;
	}
	free(intmatrix);
}

int	close_window(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_int_matrix(data->int_matrix, data);
	free(data);
	exit(0);
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 69)
		data->zoom += 3;
	if (key == 78)
		data->zoom -= 3;
	if (key == 86)
		data->angle += 0.05;
	if (key == 88)
		data->angle -= 0.05;
	if (key == 53)
		close_window(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

t_fdf	*ft_init(t_fdf *data, char *filename)
{
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (NULL);
	data->shift_x = 300;
	data->shift_y = 300;
	data->angle = 0.523599;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	data->max_value = 0;
	data->min_value = 0;
	data->height = get_height(filename);
	data->width = get_width(filename);
	return (data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = NULL;
	(void)argc;
	data = ft_init(data, argv[1]);
	if (!data)
		return (-1);
	parse(argv[1], data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 1L << 2, close_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
