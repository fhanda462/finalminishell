/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 04:25:47 by hazali            #+#    #+#             */
/*   Updated: 2026/02/26 04:34:09 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../inc/utils.h"

static void	free_env_array(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
}

static int	count_env_nodes(t_env *env_list)
{
	int		count;
	t_env	*current;

	count = 0;
	current = env_list;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

char	**env_list_to_array(t_env *env_list)
{
	char	**env_array;
	t_env	*current;
	int		count;
	int		i;
	char	*tmp;

	count = count_env_nodes(env_list);
	env_array = malloc(sizeof(char *) * (count + 1));
	if (!env_array)
		return (NULL);
	current = env_list;
	i = 0;
	while (current)
	{
		tmp = ft_strjoin(current->key, "=");
		env_array[i] = ft_strjoin(tmp, current->value);
		if (!env_array[i])
			return (free(tmp), free_env_array(env_array, i), NULL);
		free(tmp);
		current = current->next;
		i++;
	}
	env_array[i] = NULL;
	return (env_array);
}

t_env	*init_env_list(char **envp)
{
	t_env	*env_list;
	t_env	*new_node;
	int		i;

	env_list = NULL;
	i = 0;
	while (envp[i])
	{
		new_node = create_env_node(envp[i]);
		if (new_node)
			add_env_node(&env_list, new_node);
		i++;
	}
	return (env_list);
}

t_env	*create_env_node(char *env_str)
{
	t_env	*new_node;
	char	*equal;

	equal = ft_strchr(env_str, '=');
	if (!equal)
		return (NULL);
	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = ft_substr(env_str, 0, equal - env_str);
	new_node->value = ft_strdup(equal + 1);
	new_node->next = NULL;
	return (new_node);
}
