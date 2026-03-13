/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:44:13 by hazali            #+#    #+#             */
/*   Updated: 2025/11/07 20:09:05 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptn, int value, size_t count)
{
	unsigned char	*res;

	res = (unsigned char *)ptn;
	while (count > 0)
	{
		res[count - 1] = value;
		count--;
	}
	return (ptn);
}
/*
#include <stdio.h>

int	main(void)
{
	char a[10] = "012346789";
	printf("%s \n", a);
	ft_memset(a, 'X', 10);
	printf("%s \n", a);
}*/
