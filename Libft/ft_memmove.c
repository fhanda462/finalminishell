/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:44:45 by hazali            #+#    #+#             */
/*   Updated: 2025/11/06 19:11:04 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	if (dest > src)
	{
		i = size;
		while (i-- > 0)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	else
	{
		i = 0;
		while (i < size)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };
	void * source = (void *) data;
		void * destination = (void *) ( data + 1 );
	ft_memmove(destination, source, 10*sizeof(int));
	data[0]=10;
	for (int i=0; i<10; i++)
	{
			printf( "%d ", data[i] );
		}
}*/
