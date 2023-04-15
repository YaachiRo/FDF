/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:36:48 by idelfag           #+#    #+#             */
/*   Updated: 2023/04/15 22:36:48 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	wdcount(const char *s, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != sep)
			i++;
	}
	return (count);
}

int    get_rows(char *filename)
{   
    int rows;
    int fd;

    rows = 0;
    fd = open(filename, O_RDONLY, 0);
    while (get_next_line(fd))
        rows++;
    close(fd);
    return(rows);
}

int get_colums(char *filename)
{
    int colums;
    int fd;
    char *line;

    fd = open(filename, O_RDONLY, 0);
    line = get_next_line(fd);
    colums = wdcount(line, ' ');
    free(line);
    close(fd);
    return(colums);
}

void    fill_map(int *row, char *line)
{
    char **tmp;
    int i;

    i = 0;
    tmp = ft_split(line, ' ');
    while(tmp[i])
    {
        row[i] = ft_atoi(tmp[i]);
        free(tmp[i]);
        i++;
    }
    free(tmp);
}

void read_fdf(char *filename, t_fdf *fdf)
{
    int fd;
    char *line;
    int i;

    i = 0;
    fd = open(filename, O_RDONLY, 0);
    fdf->rows = get_rows(filename);
    fdf->colums = get_colums(filename);
    fdf->map = (int **)malloc(sizeof(int *) * (fdf->rows + 1));
    while(i <= fdf->rows)
    {
        fdf->map[i] = (int *)malloc(sizeof(int) * (fdf->colums + 1));
        i++;
    }
    i = 0;
    while(i <= fdf->rows)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        fill_map(fdf->map[i], line);
        free(line);
        i++;
    }
    free(line);
    fdf->map[i] = NULL;
    close(fd);
}