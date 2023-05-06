#include "fdf.h"

int	which(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

float	gtfm(float *x, float *y, t_fdf *fdf)
{
	t_matrex	*center;
	float		z;
	float		old_z;

	center = avg(fdf);
	z = (fdf->map[(int)*y][(int)*x] * fdf->sclr);
	old_z = z;
	*x -= center->matrex[0][0];
	*y -= center->matrex[1][0];
	z -= center->matrex[2][0];
	projection(x, y, &z, *fdf);
	*x += center->matrex[0][0];
	*y += center->matrex[1][0];
	*x += fdf->shiftx;
	*y += fdf->shifty;
	free_mt(center);
	return (old_z);
}

void	dda(float *array, t_fdf *fdf)
{
	t_vars	vars;
	float	z;
	float	z_end;

	fdf->x = array[0];
	fdf->y = array[1];
	fdf->x_end = array[2];
	fdf->y_end = array[3];
	z = gtfm(&fdf->x, &fdf->y, fdf);
	z_end = gtfm(&fdf->x_end, &fdf->y_end, fdf);
	if (z || z_end)
		fdf->color = 0xffd700;
	else if (!z && !z_end)
		fdf->color = 0x863ca2;
	vars.dx = fdf->x_end - fdf->x;
	vars.dy = fdf->y_end - fdf->y;
	vars.step = which(fabs(vars.dx), fabs(vars.dy));
	vars.dx /= vars.step;
	vars.dy /= vars.step;
	while ((int)(fdf->x - fdf->x_end) || (int)(fdf->y - fdf->y_end))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x, fdf->y, fdf->color);
		fdf->x += vars.dx;
		fdf->y += vars.dy;
	}
}

// void draw_bg(t_fdf *fdf)
// {

// 	int i = 0;
// 	int j = 0;
// 	while (i < 800)
// 	{
// 		j = 0;
// 		while (j < 1000)
// 		{
// 			mlx_pixel_put(fdf->mlx, fdf->win, i, j, 0x3e5059);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// draw_bg(fdf);

float	*array(float x, float y, float x_end, float y_end)
{
	float	*array;

	array = malloc(sizeof(float) * 4);
	array[0] = x;
	array[1] = y;
	array[2] = x_end;
	array[3] = y_end;
	return (array);
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->colums)
		{
			if (x < fdf->colums - 1)
			{
				fdf->array1 = array((float)x, (float)y, (float)x + 1, (float)y);
				dda(fdf->array1, fdf);
				free(fdf->array1);
			}
			if (y < fdf->rows - 1)
			{
				fdf->array2 = array((float)x, (float)y, (float)x, (float)y + 1);
				dda(fdf->array2, fdf);
				free(fdf->array2);
			}
			x++;
		}
		y++;
	}
}
