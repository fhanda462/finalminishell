/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:46:17 by hazali            #+#    #+#             */
/*   Updated: 2025/11/07 18:44:48 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int charset)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)charset)
			return ((char *)&s[i]);
	}
	if (s[i] == (char)charset)
		return ((char *)&s[i]);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char a[10] = "0423456789";
	char b[10];
	char	*c;

	printf("%s \n", a);
	c = ft_strchr(a, '4');
	printf("%s \n", c);
}*/
