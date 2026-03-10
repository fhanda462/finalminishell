/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:46:16 by hazali            #+#    #+#             */
/*   Updated: 2026/02/20 16:53:34 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *str, char charset)
{
	int	i;
	int	len;

	len = 1;
	if (!str || ft_strlen(str) == 0)
		return (len);
	i = 0;
	while (str[++i])
	{
		if (str[i - 1] != charset && str[i] == charset)
			len++;
	}
	if (str[i - 1] != charset)
		len++;
	return (len);
}

static int	ft_word_len(char const *str, char charset)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!str)
		return (len);
	while (str[i] && str[i] != charset)
	{
		len++;
		i++;
	}
	len++;
	return (len);
}

static unsigned int	fnclcpy(char *dest, char const *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

char	**ft_split(char const *str, char charset)
{
	char	**strs;
	int		len;
	int		i;
	int		j;

	strs = (char **)malloc(sizeof(char *) * (ft_len(str, charset)));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_len(str, charset) - 1)
	{
		while (str[i] && str[i] == charset)
			i++;
		len = ft_word_len(str + i, charset);
		strs[j] = (char *)malloc(sizeof(char) * len);
		if (!strs[j])
			return (NULL);
		fnclcpy(strs[j++], str + i, len);
		i += len;
	}
	strs[j] = NULL;
	return (strs);
}

// #include <stdio.h>
//  int	main(void)
//  {
// 	char	*str = "";
// 	char	sep = ' ';
// 	char	**words = ft_split(str, sep);
// 	int i = 0;

// 	printf("allocation totale de char* %d \nallocation de char %d\n",
// 		ft_len(str, sep), ft_word_len(str +1, sep));

// 	printf("Before: %s\nAfter: \n", str);
// 	while (words[i])
// 	{
// 		printf("index %d %s\n", i, words[i]);
// 		//free(words[i]);
// 		i++;

// 	}
// 	printf("le word 0 est %s \n", words[1]);

//  }