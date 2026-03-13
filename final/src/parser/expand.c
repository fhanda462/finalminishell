/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:31:49 by hazali            #+#    #+#             */
/*   Updated: 2026/02/26 02:44:30 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_var_value(char *var_name, t_minishell *shell)
{
	t_env	*tmp;
	char	*exit;

	if (ft_strcmp(var_name, "?") == 0)
	{
		exit = ft_itoa(shell->exit_s);
		return (exit);
	}
	tmp = shell->envlst;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, var_name) == 0)
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (ft_strdup(""));
}

int	is_special_char(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '"' || c == '\''
		|| c == '$' || c == '\0');
}

char	*extract_var_name(char *str, int *index)
{
	int		start;
	int		len;
	char	*var_name;

	(*index)++;
	if (str[*index] == '?')
	{
		(*index)++;
		return (ft_strdup("?"));
	}
	start = *index;
	while (str[*index] && !is_special_char(str[*index]))
		(*index)++;
	len = *index - start;
	if (len == 0)
		return (ft_strdup(""));
	var_name = ft_substr(str, start, len);
	return (var_name);
}

char	**expand_args(char **args, t_minishell *shell)
{
	char	**expanded_args;
	char	**clean_args;
	int		i;

	if (!args)
		return (NULL);
	expanded_args = malloc(sizeof(char *) * (count_args(args) + 1));
	if (!expanded_args)
		return (NULL);
	i = 0;
	while (args[i])
	{
		expanded_args[i] = expand_variables(args[i], shell);
		if (!expanded_args[i])
			return (ft_free_expandes_args(expanded_args, i), NULL);
		i++;
	}
	expanded_args[i] = NULL;
	clean_args = remove_empty_args(expanded_args);
	i = 0;
	while (expanded_args[i])
		free(expanded_args[i++]);
	free(expanded_args);
	return (clean_args);
}

char	*ft_strjoin_char(char *s, char c)
{
	char	*result;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	result = malloc(len + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = c;
	result[i + 1] = '\0';
	return (result);
}
