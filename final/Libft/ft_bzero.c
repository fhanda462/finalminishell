/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:11:20 by hazali            #+#    #+#             */
/*   Updated: 2025/11/27 18:01:12 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptn, size_t count)
{
	ft_memset(ptn, 0, count);
}

// #include <stdio.h>
// int main()
// {
// 	char a[10] = "012346789";
// 	printf("%s \n", a);
// 	ft_bzero(a, 10);
// 	printf("%s \n", a);	
// }
