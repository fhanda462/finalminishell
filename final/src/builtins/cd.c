/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:09:52 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:29:11 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*ft_get_env_value(t_env *env, char *key)
{
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

static void	set_env(t_env **env, char *key, char *value)
{
	t_env	*tmp;
	t_env	*new;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
	new = ft_calloc(1, sizeof(t_env));
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = *env;
	*env = new;
}

static char	*get_path(char **args, t_env *env)
{
	char	*path;

	if (!args[1])
	{
		path = ft_get_env_value(env, "HOME");
		if (!path)
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), NULL);
		return (path);
	}
	if (!ft_strcmp(args[1], "-"))
	{
		path = ft_get_env_value(env, "OLDPWD");
		if (!path)
			return (ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2), NULL);
		ft_putendl_fd(path, 1);
		return (path);
	}
	if (!ft_strcmp(args[1], "~"))
	{
		path = ft_get_env_value(env, "HOME");
		if (!path)
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), NULL);
		return (path);
	}
	return (args[1]);
}

int	ft_cd(char **args, t_minishell *shell)
{
	char	*path;
	char	old_pwd[4096];
	char	new_pwd[4096];

	if (args[1] && args[2])
		return (ft_putstr_fd("minishell: cd: too many arguments\n", 2), 1);
	if (!getcwd(old_pwd, 4096))
		return (perror("minishell: cd"), 1);
	path = get_path(args, shell->envlst);
	if (!path)
		return (1);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	set_env(&shell->envlst, "OLDPWD", old_pwd);
	if (getcwd(new_pwd, 4096))
		set_env(&shell->envlst, "PWD", new_pwd);
	return (0);
}
