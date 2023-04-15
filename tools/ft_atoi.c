/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:11:08 by idelfag           #+#    #+#             */
/*   Updated: 2023/04/15 23:31:34 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	n;
	int				sign;

	if (str == NULL)
		exit(1);
	sign = 1;
	n = 0;
	while (str[0] == 32 || (str[0] >= 9 && str[0] <= 13))
		str++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(str[0]))
	{
		n *= 10;
		n += (str[0] - '0');
		str++;
		if (n > LLONG_MAX && sign == -1)
			return (0);
		if (n > LLONG_MAX && sign == 1)
			return (-1);
	}
	return ((int)n * sign);
}
