/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:09:37 by hazali            #+#    #+#             */
/*   Updated: 2026/02/25 04:41:53 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	is_valid_identifier(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	while (str[++i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
	}
	return (1);
}

static void	print_export(t_env *env)
{
	while (env)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(env->key, STDOUT_FILENO);
		if (env->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(env->value, STDOUT_FILENO);
			ft_putchar_fd('"', STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		env = env->next;
	}
}

static void	add_or_update_env(char *key, char *value, t_env **env_list)
{
	t_env	*curr;
	t_env	*new;

	curr = *env_list;
	while (curr)
	{
		if (!ft_strcmp(curr->key, key))
		{
			if (value)
			{
				free(curr->value);
				curr->value = ft_strdup(value);
			}
			return ;
		}
		curr = curr->next;
	}
	new = ft_calloc(1, sizeof(t_env));
	new->key = ft_strdup(key);
	if (value)
		new->value = ft_strdup(value);
	else
		new->value = NULL;
	new->next = *env_list;
	*env_list = new;
}

static int	process_export_arg(char *arg, t_env **envlst)
{
	char	*equal;
	char	*key;
	char	*value;

	if (!is_valid_identifier(arg))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd("': not a valid identifier", 2);
		return (1);
	}
	equal = ft_strchr(arg, '=');
	if (equal)
	{
		*equal = '\0';
		key = arg;
		value = equal + 1;
		add_or_update_env(key, value, envlst);
		*equal = '=';
	}
	else
		add_or_update_env(arg, NULL, envlst);
	return (0);
}

int	ft_export(char **args, t_minishell *shell)
{
	int	i;
	int	ret;

	if (!args[1])
	{
		print_export(shell->envlst);
		return (0);
	}
	ret = 0;
	i = 1;
	while (args[i])
	{
		if (process_export_arg(args[i], &shell->envlst))
			ret = 1;
		i++;
	}
	return (ret);
}
