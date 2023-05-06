/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:41:48 by idelfag           #+#    #+#             */
/*   Updated: 2023/04/18 00:41:48 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rows(char *filename)
{
	int		rows;
	int		fd;
	char	*line;

	rows = 0;
	fd = open(filename, O_RDONLY, 0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		rows++;
	}
	close(fd);
	return (rows);
}

int	get_colums(char *filename)
{
	int		colums;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	colums = words_count(line, ' ');
	free(line);
	close(fd);
	return (colums);
}

void	fill_map(int *row, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(line, ' ');
	while (tmp[i])
	{
		row[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	init(char *filename, t_fdf *fdf)
{
	if (!ft_strnstr(filename, ".fdf", (ft_strlen(filename))))
		error("file format not compatible\n", 1);
	fdf->fd = open(filename, O_RDONLY, 0);
	if (fdf->fd == -1)
		error("failed to open file\n", 1);
	fdf->rows = get_rows(filename);
	fdf->colums = get_colums(filename);
	fdf->map = (int **)malloc(sizeof(int *) * (fdf->rows + 1));
}

void	read_fdf(char *filename, t_fdf *fdf)
{
	char	*line;
	int		i;

	i = 0;
	init(filename, fdf);
	while (i < fdf->rows)
	{
		fdf->map[i] = (int *)malloc(sizeof(int) * (fdf->colums + 1));
		i++;
	}
	i = 0;
	while (i < fdf->rows)
	{
		line = get_next_line(fdf->fd);
		if (!line)
			break ;
		fill_map(fdf->map[i], line);
		free(line);
		i++;
	}
	fdf->map[i] = NULL;
	close(fdf->fd);
}
