/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:07:54 by hazali            #+#    #+#             */
/*   Updated: 2025/11/11 12:29:56 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_n(int n)
{
	int		i;
	long	l;

	l = n;
	i = 1;
	if (l < 0)
	{
		l = -l;
		i++;
	}
	while ((l / 10) > 0)
	{
		i++;
		l = l / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	l;
	int		len;

	len = size_n(n) + 1;
	l = n;
	res = (char *)malloc(sizeof(char) * (len));
	if (!res)
		return (NULL);
	if (l < 0)
	{
		res[0] = '-';
		l = -l;
	}
	res[--len] = '\0';
	if (l == 0)
		res[0] = '0';
	while (l)
	{
		res[--len] = l % 10 + '0';
		l = l / 10;
	}
	return (res);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
printf("int1 est %d \n", size_n(-123));
printf("int1 est %s \n", ft_itoa(-123));
}*/