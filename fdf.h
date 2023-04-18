/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:15:26 by idelfag           #+#    #+#             */
/*   Updated: 2023/04/18 00:38:26 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
#define FDF_H

# include "gnl/get_next_line.h"
# include "tools/tools.h"
#include <fcntl.h>

typedef struct s_fdf
{
     int rows;
     int **map;
     int colums;
     int fd;
}                       t_fdf   ;

void read_fdf(char *filename, t_fdf *fdf);
void error(char *str, int x);


#endif