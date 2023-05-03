#include "fdf.h"

int which(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

matrex_t *projection_mt(matrex_t *point)
{
	double values[] = {1, 0, 0, 0, 1, 0};

	matrex_t *projection = creat_matrex(2, 3);
	if (projection == NULL)
		exit(127);
	fill_mt(projection, values);
	matrex_t *result = mt_multiplication(projection, point);
	free_mt(projection);
	return result;
}

matrex_t *avg(t_fdf fdf)
{
	matrex_t *center = creat_matrex(3, 1);
	int i = 0, j = 0;
	double total_z = 0;
	double total_y = 0;
	double total_x = 0;
	int total_point = fdf.colums * fdf.rows;

	while (i < fdf.rows)
	{
		j = 0;
		while (j < fdf.colums)
		{
			total_z += fdf.map[i][j];
			total_x += j;
			total_y += i;
			j++;
		}
		i++;
	}
	double values[] = {total_x / total_point, total_y / total_point, total_z / total_point};
	fill_mt(center, values);
	return (center);
}

matrex_t *y_rotation(float theta)
{
	double values[] = {
		cos(theta), 0, sin(theta),
		0, 1, 0,
		-sin(theta), 0, cos(theta)};

	matrex_t *rotation_mt = creat_matrex(3, 3);
	fill_mt(rotation_mt, values);
	return (rotation_mt);
}

matrex_t *x_rotation(float theta)
{
	double values[] = {
		1, 0, 0,
		0, cos(theta), -sin(theta),
		0, sin(theta), cos(theta)};

	matrex_t *rotation_mt = creat_matrex(3, 3);
	fill_mt(rotation_mt, values);
	return (rotation_mt);
}

matrex_t *z_rotation(float theta)
{
	double values[] = {
		cos(theta), -sin(theta), 0,
		sin(theta), cos(theta), 0,
		0, 0, 1};

	matrex_t *rotation_mt = creat_matrex(3, 3);
	fill_mt(rotation_mt, values);
	return (rotation_mt);
}

double z_scale(float zoom)
{
	if ((zoom / 10) <= 0.1)
		return 0.1;
	return (zoom / 10);
}

matrex_t *scaler(int zoom)
{
	double values[] = {
		zoom, 0, 0,
		0, zoom, 0,
		0, 0, z_scale(zoom)};

	matrex_t *scal_mt = creat_matrex(3, 3);
	fill_mt(scal_mt, values);
	return (scal_mt);
}
matrex_t *rotation_mt(matrex_t *point, float thetax, float thetay, float thetaz)
{
	matrex_t *y_rotation_mt = y_rotation(thetay);
	matrex_t *x_rotation_mt = x_rotation(thetax);
	matrex_t *z_rotation_mt = z_rotation(thetaz);
	matrex_t *result = mt_multiplication(y_rotation_mt, point);
	matrex_t *tmp;
	tmp = mt_multiplication(x_rotation_mt, result);
	free_mt(result);
	result = tmp;
	tmp = mt_multiplication(z_rotation_mt, result);
	free_mt(result);
	result = tmp;
	free_mt(y_rotation_mt);
	free_mt(x_rotation_mt);
	free_mt(z_rotation_mt);
	return (result);
}

void projection(float *x, float *y, float *z, t_fdf fdf)
{

	double values[] = {*x, *y, *z};
	matrex_t *mt = creat_matrex(3, 1);
	fill_mt(mt, values);
	matrex_t *scaller = scaler(fdf.zoom);
	matrex_t *scaled = mt_multiplication(scaller, mt);
	matrex_t *rotated = rotation_mt(scaled, fdf.angle, fdf.angle2, fdf.angle3);
	matrex_t *result = projection_mt(rotated);
	*x = result->matrex[0][0];
	*y = result->matrex[1][0];
	free_mt(mt);
	free_mt(scaller);
	free_mt(scaled);
	free_mt(rotated);
	free_mt(result);
}

void dda(float x, float y, float x_end, float y_end, t_fdf *fdf)
{
	float dx;
	float dy;
	int step;

	fdf->z = (fdf->map[(int)y][(int)x] * fdf->sclr);
	fdf->z_end = (fdf->map[(int)y_end][(int)x_end] * fdf->sclr);
	if (fdf->z || fdf->z_end)
		fdf->color = 0xffd700;
	else if (!fdf->z && !fdf->z_end)
		fdf->color = 0x863ca2;
	matrex_t *center = avg(*fdf);
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
	dx = x_end - x;
	dy = y_end - y;
	step = which(fabs(dx), fabs(dy));
	dx /= step;
	dy /= step;
	while ((int)(x - x_end) || (int)(y - y_end))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, fdf->color);
		x += dx;
		y += dy;
	}
}

void draw_bg(t_fdf *fdf)
{

	int i = 0;
	int j = 0;
	while (i < 800)
	{
		j = 0;
		while (j < 1000)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, i, j, 0x3e5059);
			j++;
		}
		i++;
	}
}

void draw_map(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	// draw_bg(fdf);
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
