
# include <math.h>
# include "fdf.h"

int which(float x, float y)
{
    if (x > y)
        return(x);
    return(y);
}

float mod(float i)
{
    if (i < 0)
        i *= -1;
    return(i);
}

void get_z(float *x, float*y, int z, float angle, float angle2)
{
    *x = (*x - *y) * cos(angle);
    *y = (*y + *x) * sin(angle2) - z; 
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
    if (z || z_end)
        fdf->color = 0x9ac27d;
    else if (!z && !z_end)
        fdf->color = 0x379ed5;
    get_z(&x, &y, z, fdf->angle, fdf->angle2);
    get_z(&x_end, &y_end, z_end, fdf->angle, fdf->angle2);
    x += fdf->shiftx;
    y += fdf->shifty;
    x_end += fdf->shiftx;
    y_end += fdf->shifty;
    dx = x_end - x;
    dy = y_end - y;
    step = which(mod(dx), mod(dy));
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