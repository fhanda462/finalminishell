/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:48:12 by hazali            #+#    #+#             */
/*   Updated: 2025/11/11 19:19:37 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t length)
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while ((str1[i] || str2[i]) && i < length)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		else
			i++;
	}
	return (0);
}
/*int	ft_strncmp( const char *str1, const char *str2, size_t length )
{
	size_t	i;

	i = 0;
	while (str1[i] == str2[i] && i < length)
	{
		i++;
	}
	return (str1[i] - str2[i]);
}*/
/*#include <stdio.h>

int	main(void) {

	const char *str1 = "test6";
	const char *str2 = "test3";
	size_t size = sizeof( char ) * 5;

	printf( "%d \n", ft_strncmp( str1, str2, size) );

	return (0);
}*/
