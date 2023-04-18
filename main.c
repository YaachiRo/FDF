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

void error(char *str, int x)
{
     write(2, str, ft_strlen(str));
     exit(x);
}

int main(int ac, char **av)
{
     t_fdf fdf;
     

     if (ac != 2)
          error("argumant are not valid\n", 1);
     read_fdf(av[1], &fdf);
}