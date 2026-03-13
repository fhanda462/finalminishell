/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammm <hammm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:24:22 by hazali            #+#    #+#             */
/*   Updated: 2026/02/12 11:18:25 by hammm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (!slen || start > slen - 1)
		return (ft_strdup(""));
	i = 0;
	while (s[start + i] && i + 1 <= len)
		i++;
	substr = ft_calloc((i + 1), sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

/*#include <stdio.h>

int	main(void)
{
	char const *s = "0123456789";
	printf("%s", ft_substr(s, 9, 10));

}*/