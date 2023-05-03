/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:14:19 by idelfag           #+#    #+#             */
/*   Updated: 2023/04/18 00:50:11 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float angle(float angle)
{
    if(angle > M_PI)
        angle = -1 * M_PI;
    else if(angle < -1 * M_PI)
        angle = -1 * M_PI;
    return angle;
}

int key_hook(int x, t_fdf *fdf)
{
    if(x == 65362)
        fdf->shifty -= 25;
    if(x == 65364)
        fdf->shifty += 25;
    if(x == 65363)
        fdf->shiftx += 25;
    if(x == 65361)
        fdf->shiftx -= 25;
    if(x == 119)
        fdf->angle += 0.1;
    if(x == 115)
        fdf->angle -= 0.1;
    if(x == 100)
        fdf->angle2 += 0.1;
    if(x == 97)
        fdf->angle2 -= 0.1;
    if(x == 122)
        fdf->angle3 += 0.1;
    if(x == 120)
        fdf->angle3 -= 0.02;
    if(x == 98)
    {
        fdf->angle = angle(fdf->angle + 0.01);
        fdf->angle2 = angle(fdf->angle2 - 0.05);
        fdf->angle3 = angle(fdf->angle3 + 0.08);
    }
    if(x == 65438)
    {
        fdf->angle = 0;
        fdf->angle2 = 0;
        fdf->angle3 = 0;
    }
    if(x == 111)
        fdf->zoom -= 2;
    if(x == 105)
        fdf->zoom += 2;
    if(x == 110)
   {
        fdf->sclr -= 0.1;
        if (!fdf->sclr)
            fdf->sclr -= 0.1;
    }
    if(x == 109)
    {
        fdf->sclr += 0.1;
        if (!fdf->sclr)
            fdf->sclr += 0.1;
    }
    if(x == 65307)
            exit(0);
    fdf->afk = get_time();
    mlx_clear_window(fdf->mlx, fdf->win);
    draw_map(fdf);
    return(0);
}

void error(char *str, int x)
{
    int i = write(2, str, ft_strlen(str));
    (void)i;
    exit(x);
}

long int    get_time(void)
{
    long int                curr_time;
    struct timeval  time;

    gettimeofday(&time, NULL);
    curr_time = time.tv_sec * THOUSAND + time.tv_usec / THOUSAND;
    return (curr_time);
}

int     uu_sleep(long int ms)
{
    long int        start_time;

    start_time = get_time();
    while (get_time() < start_time + ms)
    usleep(100);
    return (0);
}

int animate(t_fdf *fdf)
{
    fdf->t1 = get_time();
    if( fdf->t1 >= (fdf->t2 + RATE) && fdf->t1 > (fdf->afk + THOUSAND))
    {
        fdf->t2 = fdf->t1;
        if(fdf->angle2 > SWEET_Y)
            fdf->angle2 -= ANGLERATE;
        if(fdf->angle2 < SWEET_Y)
            fdf->angle2 += ANGLERATE;
        if(fdf->angle3 > SWEET_Z)
            fdf->angle3 -= ANGLERATE;
        if(fdf->angle3 < SWEET_Z)
            fdf->angle3 += ANGLERATE;
        fdf->angle -= ANGLERATE;
        mlx_clear_window(fdf->mlx, fdf->win);
        draw_map(fdf);
    }
    return  0;
}

int	event(int keycode, t_fdf *fdf)
{
    (void) fdf;
    (void) keycode;
    exit(0);
	return (0);
}

int main(int ac, char **av)
{
    t_fdf *fdf = malloc(sizeof(t_fdf));

    if (ac != 2)
        error("argumant are not valid\n", 1);
    read_fdf(av[1], fdf);
    fdf->zoom = 30;
    fdf->shiftx = (800 / 2) - (fdf->rows * 16/ 2);
    fdf->shifty = (1000 / 2) - (fdf->colums * 16 / 2);
    fdf->angle = 0.3;
    fdf->angle2 = 0.3;
    fdf->angle3 = 0.3;
    fdf->t2 = 0;
    fdf->afk = 0;
    fdf->sclr = 1;
    fdf->mlx = mlx_init();
    fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "FDF");
    draw_map(fdf);
    mlx_key_hook(fdf->win, key_hook, fdf);
    mlx_hook(fdf->win, 17, 0l, event, fdf);
    mlx_loop_hook(fdf->mlx, animate, fdf);
    mlx_loop(fdf->mlx);
}