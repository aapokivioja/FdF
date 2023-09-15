/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 18:31:35 by akivioja      #+#    #+#                 */
/*   Updated: 2023/09/15 17:28:13 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_height(char *filename)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(filename, O_RDONLY, 0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	count_words(char *line)
{
	int	word_count;
	int	index;

	word_count = 0;
	index = 0;
	while (line[index])
	{
		while (line[index] == ' ' && line[index] != '\0')
			index++;
		if (line[index])
			word_count++;
		while (line[index] != ' ' && line[index] != '\0')
			index++;
	}
	return (word_count);
}

int	get_width(char *filename)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	width = count_words(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (width);
}

void	fill_matrix(int *row, char *line, t_fdf *data)
{
	char	**nums;
	int		index;
	int		num;

	nums = ft_split(line, ' ');
	index = 0;
	while (nums[index])
	{
		num = ft_atoi(nums[index]);
		row[index] = num;
		if (num < data->min_value)
			data->min_value = num;
		else if (num > data->max_value)
			data->max_value = num;
		free(nums[index]);
		index++;
	}
	free(nums);
}

void	parse(char *filename, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	data->int_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!(data->int_matrix))
		close_window(data);
	i = 0;
	while (i < data->height)
	{
		data->int_matrix[i++] = (int *)malloc(sizeof(int) *(data->width));
		if (!(data->int_matrix[i - 1]))
			close_window(data);
	}
	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		fill_matrix(data->int_matrix[i], line, data);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
