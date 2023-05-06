#include "fdf.h"

void	menu(t_fdf *fdf)
{
	int		x;
	void	*mlx;
	void	*win;

	x = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 20, x += 60, 0x11e3cd, "CONTROL BUTTONS");
	mlx_string_put(mlx, win, 10, x += 30, 0xffd700, "ZOOM CONTROL");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "O To Zoom Out");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "I To Zoom In");
	mlx_string_put(mlx, win, 10, x += 30, 0xffd700, "Move :");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "Direction buttons");
	mlx_string_put(mlx, win, 10, x += 30, 0xffd700, "Rotatation:");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "X : A - D");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "Y : W - S");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "Z : Z - X");
	mlx_string_put(mlx, win, 10, x += 30, 0xffd700, "Projection");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "iconic : NUM 0");
	mlx_string_put(mlx, win, 10, x += 30, 0xffd700, "CONTROL HEIGHT Z");
	mlx_string_put(mlx, win, 20, x += 20, 0x863ca2, "M - N");
	mlx_string_put(mlx, win, 60, x += 45, 0x11e3cd, "HAVE FUN <3");
}
