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

int key_hook(int x, t_fdf *fdf)
{
    printf("%d\n", x);
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
    {
       // fdf->angle += 0.1;
       // fdf->angle2 += 0.02;
        fdf->angle3 += 0.1;
    }
    if(x == 120)
    {
        //fdf->angle -= 0.1;
        //fdf->angle2 -= 0.02;
        fdf->angle3 -= 0.02;
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
    if(x == 65307)
        exit(0);
    mlx_clear_window(fdf->mlx, fdf->win);
    draw_map(fdf);
    return(0);
}

// int mouse_hook(int action, t_fdf *fdf)
// {
//     printf("%d\n", action);
//     if (action == 5)
//         fdf->zoom -= 2;
//     if (action == 4)
//         fdf->zoom += 2;
//     mlx_clear_window(fdf->mlx, fdf->win);
//     draw_map(fdf);
//     return(0);
// }

void error(char *str, int x)
{
     int i = write(2, str, ft_strlen(str));
     (void)i;
     exit(x);
}

int main(int ac, char **av)
{
    t_fdf fdf;
    
    if (ac != 2)
        error("argumant are not valid\n", 1);
    read_fdf(av[1], &fdf);
    fdf.zoom = 30;
    fdf.shiftx = 150;
    fdf.shifty = 150;
    fdf.angle = 0.3;
    fdf.angle2 = 0.3;
    fdf.angle3 = 0.3;
    fdf.mlx = mlx_init();
    fdf.win = mlx_new_window(fdf.mlx, 1000, 800, "FDF");
    draw_map(&fdf);
    mlx_key_hook(fdf.win, key_hook, &fdf);
    //mlx_mouse_hook(fdf.win, mouse_hook, &fdf);
    mlx_loop(fdf.mlx);
}