/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:48:01 by hazali            #+#    #+#             */
/*   Updated: 2025/11/07 19:00:45 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int charset)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)charset)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char a[20] = "xyd423456789kxy";
	char b[20] = "yx4";
	char	*c;
	char a[10] = "0123467879";
	printf("%s \n", a);
	printf("%s \n", (char *)ft_strrchr(a, '7'));
}*/
