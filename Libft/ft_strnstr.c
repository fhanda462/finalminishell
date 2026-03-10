/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:50:15 by hazali            #+#    #+#             */
/*   Updated: 2025/11/13 09:30:53 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !len)
		return (NULL);
	if (s2[0] == '\0' || s1 == s2)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < len)
		{
			if (s1[i + j] == '\0' && s2[j] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)(s1 + i));
		i++;
	}
	return (0);
}
/*#include <stdio.h>
int	main(void)
{
	const char	*s1 = "Foo Bar ui";
	const char	*s2 = "Foo Bar ui";
	char		*ptr;

	ptr = ft_strnstr(s1, s2, 4);
	printf("%s \n", ptr);
}*/
