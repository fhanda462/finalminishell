/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:10:16 by hazali            #+#    #+#             */
/*   Updated: 2025/11/11 12:29:03 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char const *str, char const charset)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == charset)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s1);
	k = 0;
	while (is_charset(set, s1[i]) && s1[i])
		i++;
	while (is_charset(set, s1[j - 1]) && j > i)
	{
		j--;
	}
	res = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!res)
		return (NULL);
	while (i < j)
		res[k++] = s1[i++];
	res[k] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char const *s1 = "xyd423456789kxy";
	char const *s2 = "yxd4";
	printf("%s", ft_strtrim(s1,s2));
}*/