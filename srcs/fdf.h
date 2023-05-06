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

#ifndef FDF_H
# define FDF_H

# include "../gnl/get_next_line.h"
# include "../tools/tools.h"
# include <fcntl.h>
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include "../matrex/matrex.h"
# include <sys/types.h>
# include <sys/time.h>

# define THOUSAND 1000
# define FRAME_RATE 20
# define RATE (50)
# define SWEET_Y -1.2
# define SWEET_Z 1.6
# define ANGLERATE 0.01

typedef struct s_fdf
{
	int		rows;
	int		**map;
	int		colums;
	int		fd;
	void	*win;
	void	*mlx;
	int		zoom;
	int		color;
	int		shiftx;
	int		shifty;
	float	angle;
	float	angle2;
	float	angle3;
	long	t1;
	long	t2;
	long	afk;
	float	z;
	float	z_end;
	float	sclr;
}	t_fdf;

typedef struct s_vars
{
	double	total_x;
	double	total_y;
	double	total_z;
	int		total_point;
	float	dx;
	float	dy;
	int		step;
}	t_vars;

typedef struct s_mat
{
	matrex_t	*y_rotation_mt;
	matrex_t	*x_rotation_mt;
	matrex_t	*z_rotation_mt;
	matrex_t	*rotated;
	matrex_t	*scaled;
	matrex_t	*scaller;
}	t_mat;

void		read_fdf(char *filename, t_fdf *fdf);
void		error(char *str, int x);
matrex_t	*creat_matrex(int r, int c);
matrex_t	*mt_multiplication(matrex_t *mt1, matrex_t *mt2);
void		projection(float *x, float *y, float *z, t_fdf fdf);
matrex_t	*rotation_mt(matrex_t *point, float x, float y, float z);
matrex_t	*projection_mt(matrex_t *point);
matrex_t	*avg(t_fdf *fdf);
matrex_t	*scaler(int zoom);
void		draw_map(t_fdf *fdf);
long		get_time(void);
int			animate(t_fdf *fdf);
float		angle(float angle);

#endif
