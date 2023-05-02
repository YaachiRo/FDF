/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:15:26 by idelfag           #+#    #+#             */
/*   Updated: 2023/04/18 00:38:26 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
#define FDF_H

# include "gnl/get_next_line.h"
# include "tools/tools.h"
# include <fcntl.h>
# include "mlx_linux/mlx.h"
# include <stdio.h>
# include "types.h"
# include "matrex.h"

typedef struct s_fdf
{
     int rows;
     int **map;
     int colums;
     int fd;
     void *win;
     void *mlx;
     int zoom;
     int color;
     int shiftx;
     int shifty;
     float angle;
     float angle2;
     float angle3;
}                       t_fdf   ;

void read_fdf(char *filename, t_fdf *fdf);
void error(char *str, int x);
matrex_t *creat_matrex(int r, int c);
matrex_t *mt_multiplication(matrex_t *mt1, matrex_t * mt2);
void draw_map(t_fdf *fdf);

#endif