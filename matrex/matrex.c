#include "matrex.h"

void	fill_mt(t_matrex *mt, double *values)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < mt->rows)
	{
		j = 0;
		while (j < mt->colums)
		{
			mt->matrex[i][j] = values[k];
			k++;
			j++;
		}
		i++;
	}
}

double	*create_colums(int c)
{
	int		i;
	double	*new_col;

	i = 0;
	new_col = malloc(c * sizeof(double));
	while (i < c)
	{
		new_col[i] = .0;
		i++;
	}
	return (new_col);
}

t_matrex	*creat_matrex(int rows, int colums)
{
	t_matrex	*new_mt;
	int			i;
	double		**mt;

	if (rows <= 0 || colums <= 0)
		return (NULL);
	new_mt = malloc(sizeof(t_matrex));
	i = 0;
	new_mt->rows = rows;
	new_mt->colums = colums;
	mt = malloc(sizeof(double *) * rows);
	while (i < rows)
		mt[i++] = create_colums(colums);
	new_mt->matrex = mt;
	return (new_mt);
}

t_matrex	*mt_multiplication(t_matrex *mt1, t_matrex *mt2)
{
	t_matrex	*result;
	int			i;
	int			j;
	int			k;

	i = 0;
	if (!mt1 || !mt2 || mt1->colums != mt2->rows)
		return (NULL);
	result = creat_matrex(mt1->rows, mt2->colums);
	while (i < mt1->rows)
	{
		k = 0;
		while (k < mt2->colums)
		{
			j = 0;
			while (j < mt1->colums)
			{
				result->matrex[i][k] += (mt1->matrex[i][j] * mt2->matrex[j][k]);
				j++;
			}
			k++;
		}
		i++;
	}
	return (result);
}

void	free_mt(t_matrex *mt)
{
	int	i;

	i = 0;
	while (i < mt->rows)
		free(mt->matrex[i++]);
	free(mt->matrex);
	free(mt);
}
