/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:50:58 by hazali            #+#    #+#             */
/*   Updated: 2025/11/10 13:23:35 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	res = (void *)malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_memset((unsigned char *)res, 0, nmemb * size);
	return (res);
}*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (size != 0 && nmemb > 184467440737095516 / size)
		return (NULL);
	res = (void *)malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, (nmemb * size));
	return (res);
}
/*#include <stdio.h>
int main()
{
int i;
    int *pointer = (int *) ft_calloc(-5, -5 );

    
    for ( i=0; i<9; i++ ) {
        pointer[i] = i;
    }

   
    for (i=0; i<10; i++ ) {
        printf( "%d ", pointer[i] );
    }
    printf( "\n" );

	pointer = (int *) ft_calloc(10, sizeof(int) );
	for (i=0; i<10; i++ ) {
        printf( "%d ", pointer[i] );
    }
    free( pointer );

    return 0;
}*/
