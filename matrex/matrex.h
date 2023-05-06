#ifndef MATREX_H
# define MATREX_H

# include<stdlib.h>
# include<unistd.h>
# include<math.h>

typedef struct matrex
{
	int		rows;
	int		colums;
	double	**matrex;
}	t_matrex;

t_matrex	*creat_matrex(int r, int c);
t_matrex	*mt_multiplication(t_matrex *mt1, t_matrex *mt2);
void		fill_mt(t_matrex *mt, double *values);
void		print_matrex(t_matrex *matrex);
void		free_mt(t_matrex *mt);

#endif