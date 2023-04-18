/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:33:25 by idelfag           #+#    #+#             */
/*   Updated: 2023/04/18 00:33:37 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*str;
	char	*c;
	size_t	j;

	i = 0;
	str = (char *)haystack;
	c = (char *)needle;
	if (*c && len == 0)
		return (0);
	if (*c == 0)
		return (0);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && str[i + j] == c[j] && i + j < len)
			j++;
		if (c[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}