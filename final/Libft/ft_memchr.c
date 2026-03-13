/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:48:21 by hazali            #+#    #+#             */
/*   Updated: 2025/11/10 19:35:53 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int charset, size_t size)
{
	unsigned char	*res;
	size_t			i;

	res = (unsigned char *)str;
	i = 0;
	while (i < size)
	{
		if (res[i] == (unsigned char)charset)
			return (res + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char a[10] = "012346789";
	printf("%s \n", a);
	printf("%s \n", (char *)ft_memchr(a, '7', 10));
}*/
