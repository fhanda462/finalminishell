/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:50:24 by hazali            #+#    #+#             */
/*   Updated: 2025/11/13 09:32:27 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ((str[i] <= '9' && str[i] >= '0'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
/*

#include <stdio.h>
#include <stdlib.h> 
int	main()
{
	const char *str1 = "	-42635";
	const char *str2 = "		--69584";
	
printf("str1 est %d et str2 est %d \n", ft_atoi(str1), ft_atoi(str2));
printf("str1 est %d et str2 est %d \n", atoi(str1), atoi(str2));
}*/
