#include "fdf.h"

matrex_t	*y_rotation(float theta)
{
	matrex_t	*rotation;
	double		values[9];

	values[0] = cos(theta);
	values[1] = 0;
	values[2] = sin(theta);
	values[3] = 0;
	values[4] = 1;
	values[5] = 0;
	values[6] = -sin(theta);
	values[7] = 0;
	values[8] = cos(theta);
	rotation = creat_matrex(3, 3);
	fill_mt(rotation, values);
	return (rotation);
}

matrex_t	*x_rotation(float theta)
{
	matrex_t	*rotation;
	double		values[9];

	values[0] = 1;
	values[1] = 0;
	values[2] = 0;
	values[3] = 0;
	values[4] = cos(theta);
	values[5] = -sin(theta);
	values[6] = 0;
	values[7] = sin(theta);
	values[8] = cos(theta);
	rotation = creat_matrex(3, 3);
	fill_mt(rotation, values);
	return (rotation);
}

matrex_t	*z_rotation(float theta)
{
	matrex_t	*rotation;
	double		values[9];

	values[0] = cos(theta);
	values[1] = -sin(theta);
	values[2] = 0;
	values[3] = sin(theta);
	values[4] = cos(theta);
	values[5] = 0;
	values[6] = 0;
	values[7] = 0;
	values[8] = 1;
	rotation = creat_matrex(3, 3);
	fill_mt(rotation, values);
	return (rotation);
}

matrex_t	*rotation_mt(matrex_t *point, float x, float y, float z)
{
	t_mat		mat;
	matrex_t	*result;
	matrex_t	*tmp;

	mat.y_rotation_mt = y_rotation(y);
	mat.x_rotation_mt = x_rotation(x);
	mat.z_rotation_mt = z_rotation(z);
	result = mt_multiplication(mat.y_rotation_mt, point);
	tmp = mt_multiplication(mat.x_rotation_mt, result);
	free_mt(result);
	result = tmp;
	tmp = mt_multiplication(mat.z_rotation_mt, result);
	free_mt(result);
	result = tmp;
	free_mt(mat.y_rotation_mt);
	free_mt(mat.x_rotation_mt);
	free_mt(mat.z_rotation_mt);
	return (result);
}

void	projection(float *x, float *y, float *z, t_fdf fdf)
{
	t_mat		mat;
	matrex_t	*mt;
	matrex_t	*result;
	double		values[3];

	values[0] = *x;
	values[1] = *y;
	values[2] = *z;
	mt = creat_matrex(3, 1);
	fill_mt(mt, values);
	mat.scaller = scaler(fdf.zoom);
	mat.scaled = mt_multiplication(mat.scaller, mt);
	mat.rotated = rotation_mt(mat.scaled, fdf.angle, fdf.angle2, fdf.angle3);
	result = projection_mt(mat.rotated);
	*x = result->matrex[0][0];
	*y = result->matrex[1][0];
	free_mt(mt);
	free_mt(mat.scaller);
	free_mt(mat.scaled);
	free_mt(mat.rotated);
	free_mt(result);
}
