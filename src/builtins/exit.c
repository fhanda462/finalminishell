/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:09:34 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:29:15 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == 0)
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static long long	ft_atoll(char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static int	ft_is_too_big(char *str)
{
	char	*tmp;

	tmp = str;
	if (*tmp == '-' || *tmp == '+')
		tmp++;
	if (ft_isnumber(str) == 1 && ft_strlen(tmp) < 19)
		return (0);
	if (ft_strlen(tmp) > 19)
		return (1);
	if (ft_isnumber(str) == 1 && ft_strcmp(str, "9223372036854775807") > 0)
		return (1);
	if (ft_isnumber(str) == 1 && str[0] && str[0] == '-' && ft_strcmp(str,
			"-9223372036854775808") > 0)
		return (1);
	return (0);
}

int	ft_exit(char **args, t_minishell *shell)
{
	int	exit_code;

	exit_code = shell->exit_s;
	if (!args[1])
	{
		ft_putstr_fd("exit\n", 2);
		exit(exit_code);
	}
	if (!ft_isnumber(args[1]) || ft_is_too_big(args[1]))
	{
		ft_putstr_fd(" numeric argument required\n", 2);
		exit(2);
	}
	if (args[2])
	{
		ft_putstr_fd(" too many arguments\n", 2);
		return (1);
	}
	exit_code = (unsigned char)ft_atoll(args[1]);
	exit(exit_code);
}
