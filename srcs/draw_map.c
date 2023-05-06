#include "fdf.h"

int	which(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}



void	dda(float x, float y, float x_end, float y_end, t_fdf *fdf)
{
	t_vars		vars;
	matrex_t	*center;

	fdf->z = (fdf->map[(int)y][(int)x] * fdf->sclr);
	fdf->z_end = (fdf->map[(int)y_end][(int)x_end] * fdf->sclr);
	if (fdf->z || fdf->z_end)
		fdf->color = 0xffd700;
	else if (!fdf->z && !fdf->z_end)
		fdf->color = 0x863ca2;
	center = avg(fdf);
	x -= center->matrex[0][0];
	y -= center->matrex[1][0];
	fdf->z -= center->matrex[2][0];
	x_end -= center->matrex[0][0];
	y_end -= center->matrex[1][0];
	fdf->z_end -= center->matrex[2][0];
	projection(&x, &y, &fdf->z, *fdf);
	projection(&x_end, &y_end, &fdf->z_end, *fdf);
	x += center->matrex[0][0];
	y += center->matrex[1][0];
	x_end += center->matrex[0][0];
	y_end += center->matrex[1][0];
	free_mt(center);
	x += fdf->shiftx;
	y += fdf->shifty;
	x_end += fdf->shiftx;
	y_end += fdf->shifty;
	vars.dx = x_end - x;
	vars.dy = y_end - y;
	vars.step = which(fabs(vars.dx), fabs(vars.dy));
	vars.dx /= vars.step;
	vars.dy /= vars.step;
	while ((int)(x - x_end) || (int)(y - y_end))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, fdf->color);
		x += vars.dx;
		y += vars.dy;
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

// draw_bg(fdf); under y = 0;
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
				dda(x, y, x + 1, y, fdf);
			if (y < fdf->rows - 1)
				dda(x, y, x, y + 1, fdf);
			x++;
		}
		y++;
	}
}
