/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:00:18 by idelfag           #+#    #+#             */
/*   Updated: 2023/04/18 00:34:26 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strnstr(const char *haystack, const char *needle, size_t len);
char		**ft_split(char const *s, char c);
int			words_count(const char *s, char sep);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif