/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:00:18 by idelfag           #+#    #+#             */
/*   Updated: 2023/04/12 00:20:19 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

size_t	ft_strlen(const char *s);
int	ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
int	ft_isdigit(int c);

#endif
