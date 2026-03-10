/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:43:41 by hazali            #+#    #+#             */
/*   Updated: 2026/02/26 04:31:15 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../inc/utils.h"

static int	count_non_empty_args(char **args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (args[i])
	{
		if (args[i][0] != '\0')
			count++;
		i++;
	}
	return (count);
}

char	**remove_empty_args(char **args)
{
	char	**result;
	int		count;

	if (!args)
		return (NULL);
	count = count_non_empty_args(args);
	if (count == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	return (cpy_non_empty_args(args, result));
}

char	**cpy_non_empty_args(char **args, char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (args[i][0] != '\0')
		{
			result[j] = ft_strdup(args[i]);
			if (!result[j])
			{
				while (j > 0)
					free(result[--j]);
				free(result);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}

void	exec_error(char *cmd, char *msg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}

void	exit_with_error(char *msg, int code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(code);
}
