#include <stdio.h>
#include "matrex.h"

void print_matrex(matrex_t *matrex)
{
	int	i;
	int	j;

	if(!matrex)
		return;
	i = 0;
	printf("[ \n");
	while(i < matrex->rows )
	{
		j = 0;
		printf("\t[ ");
		while(j < matrex->cols)
		{
			printf("<%f>%c", matrex->matrex[i][j], j < (matrex->cols - 1) ? ',' : ' ');
			j++;
		}
		printf("],\n");
		i++;
	}
	printf("]\n");
}

void fill_mt(matrex_t *mt, double* values)
{
	int k = 0;  // index of current value
	for (int i = 0; i < mt->rows; i++)
	{
		for (int j = 0; j < mt->cols; j++)
			mt->matrex[i][j] = values[k++];
	}
}

double *create_cols(int c)
{
	int i = 0;
	double *new_col = malloc(c * sizeof(double));
	while (i < c)
		new_col[i++] = .0;
	return (new_col);
}

matrex_t *creat_matrex(int rows, int cols)
{
	matrex_t	*new_mt;
	int			i;
	double		**mt; 
	if(rows <= 0 || cols <= 0)
		return (NULL);
	new_mt = malloc(sizeof(matrex_t));
	i = 0;
	new_mt->rows = rows;
	new_mt->cols = cols;
	mt = malloc(sizeof(double *) * rows);
	while (i < rows)
		mt[i++] = create_cols(cols);
	new_mt->matrex = mt;
	return (new_mt);
}

matrex_t	*mt_multiplication(matrex_t *mt1, matrex_t * mt2)
{
	matrex_t	*result;
	int			i;
	int			j;
	int			k;

	i = 0;
	if(!mt1 || !mt2 || mt1->cols != mt2->rows)
		return (NULL);
	result = creat_matrex(mt1->rows, mt2->cols);
	while (i < mt1->rows)
	{
		k = 0;
		while ( k < mt2->cols)
		{
			j = 0;
			while (j < mt1->cols)
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

void free_mt(matrex_t *mt)
{
	int i = 0;
	while (i < mt->rows)
		free(mt->matrex[i++]);
	free(mt->matrex);
	free(mt);
}
