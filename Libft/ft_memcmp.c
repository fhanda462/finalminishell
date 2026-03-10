/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:48:30 by hazali            #+#    #+#             */
/*   Updated: 2025/11/11 19:14:47 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				delta;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		delta = str1[i] - str2[i];
		if (delta)
			return (delta);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void) {

	int array1 [] = { 1, 85, 25, 63, 21 };
	int array2 [] = { 1, 85, 19, 63, 22 };
	size_t size = sizeof( int ) * 5;

	printf( "%d \n", ft_memcmp( array1, array2, size) );

	return (0);
}*/
