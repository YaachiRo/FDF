#include "fdf.h"

t_matrex	*projection_mt(t_matrex *point)
{
	double		values[6];
	t_matrex	*projection;
	t_matrex	*result;

	values[0] = 1;
	values[1] = 0;
	values[2] = 0;
	values[3] = 0;
	values[4] = 1;
	values[5] = 0;
	projection = creat_matrex(2, 3);
	fill_mt(projection, values);
	result = mt_multiplication(projection, point);
	free_mt(projection);
	return (result);
}

void	calculate_total(t_vars *vars, t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->rows)
	{
		j = 0;
		while (j < fdf->colums)
		{
			vars->total_z += fdf->map[i][j];
			vars->total_x += j;
			vars->total_y += i;
			j++;
		}
		i++;
	}
}

t_matrex	*avg(t_fdf *fdf)
{
	t_vars		vars;
	t_matrex	*center;
	double		values[3];

	vars.total_point = fdf->colums * fdf->rows;
	center = creat_matrex(3, 1);
	vars.total_z = 0;
	vars.total_x = 0;
	vars.total_y = 0;
	calculate_total(&vars, fdf);
	values[0] = vars.total_x / vars.total_point;
	values[1] = vars.total_y / vars.total_point;
	values[2] = vars.total_z / vars.total_point;
	fill_mt(center, values);
	return (center);
}

double	z_scale(float zoom)
{
	if ((zoom / 10) <= 0.1)
		return (0.1);
	return (zoom / 10);
}

t_matrex	*scaler(int zoom)
{
	t_matrex	*scal_mt;
	double		values[9];

	values[0] = zoom;
	values[1] = 0;
	values[2] = 0;
	values[3] = 0;
	values[4] = zoom;
	values[5] = 0;
	values[6] = 0;
	values[7] = 0;
	values[8] = z_scale(zoom);
	scal_mt = creat_matrex(3, 3);
	fill_mt(scal_mt, values);
	return (scal_mt);
}
