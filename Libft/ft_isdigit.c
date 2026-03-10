/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:29:12 by hazali            #+#    #+#             */
/*   Updated: 2025/11/04 13:29:15 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
int	main()
{
	printf("ceci est digit %d \n", ft_isdigit('7'));
	printf("ceci n est pas digit %d \n", ft_isdigit('@'));
}*/
