
# include <math.h>
# include "fdf.h"

#define STEP(a, b) (a > b ? a : b)
#define MOD(i) ((i < 0) ? -i : i)
float mod(float i)
{
    return(i < 0) ? -i : i;
}

void dda(float x, float y, float x_end, float y_end, t_fdf *fdf)
{
    float dx;
    float dy;
    int step;
    int z;
    int z_end;

    z = fdf->map[(int)y][(int)x];
    z_end = fdf->map[(int)y_end][(int)x_end];
    x *= fdf->zoom;
    y *= fdf->zoom;
    x_end *= fdf->zoom;
    y_end *= fdf->zoom;
    fdf->color = (z || z_end) ? 0xffd700 : 0xc3c7c7;
    dx = x_end - x;
    dy = y_end - y;
    step = STEP(MOD(dx), MOD(dy));
    dx /= step;
    dy /= step;
    while((int)(x - x_end) || (int)(y - y_end))
    {
        mlx_pixel_put(fdf->mlx, fdf->win, x, y, fdf->color);
        x += dx;
        y += dy;
    }
}

void draw_map(t_fdf *fdf)
{
    int x;
    int y;

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