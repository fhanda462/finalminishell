/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:09:41 by hazali            #+#    #+#             */
/*   Updated: 2026/03/13 08:56:50 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	remove_env(char *key, t_env **env_list)
{
	t_env	*curr;
	t_env	*prev;

	curr = *env_list;
	prev = NULL;
	while (curr)
	{
		if (!ft_strcmp(curr->key, key))
		{
			if (prev)
				prev->next = curr->next;
			else
				*env_list = curr->next;
			free(curr->key);
			free(curr->value);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

static void	remove_env2(char *key, char ***env)
{
	int		i;
	char	**curr;

	i = 0;
	curr = *env;
	while (curr[i])
	{
		if (!ft_strncmp(curr[i], key, ft_strlen(key)))
		{
			curr[i] = NULL;
			return ;
		}
		i++;
	}
}

int	ft_unset(char **args, t_minishell *shell)
{
	int	i;

	if (!args[1])
		return (0);
	i = 0;
	while (args[++i])
	{
		remove_env(args[i], &shell->envlst);
		remove_env2(args[i], &shell->environ);
	}
	return (0);
}
