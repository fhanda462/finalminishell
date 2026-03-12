/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:34:04 by hazali            #+#    #+#             */
/*   Updated: 2026/03/12 21:58:09 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <sys/stat.h>

char	**get_paths_env(char **envp)
{
	int		i;
	char	*path_value;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_value = envp[i] + 5;
			return (ft_split(path_value, ':'));
		}
		i++;
	}
	return (NULL);
}

char	*build_full_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full_path);
}

int	is_directory(const char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) != 0)
		return (S_ISDIR(path_stat.st_mode));
	return (1);
}

char	*check_absolute_path(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (access(cmd, F_OK) == -1)
	{
		exec_error(cmd, "No such file or directory");
		exit(127);
	}
	if (access(cmd, X_OK) == -1)
	{
		exec_error(cmd, "Permission denied");
		exit(126);
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	int		i;

	i = -1;
	if (!cmd || !cmd[0])
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		return (check_absolute_path(cmd));
	}
	paths = get_paths_env(envp);
	if (!paths)
		return (NULL);
	while (paths[++i])
	{
		full_path = build_full_path(paths[i], cmd);
		if (full_path && access(full_path, X_OK) == 0)
			return (free_split(paths), full_path);
		free(full_path);
	}
	free_split(paths);
	return (NULL);
}
