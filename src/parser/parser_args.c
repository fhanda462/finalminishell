/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:44:32 by hammm             #+#    #+#             */
/*   Updated: 2026/03/08 17:30:19 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_parse_word_redir(t_node *node, t_token **list_token)
{
	if (ft_is_redirection((*list_token)->type))
	{
		if (!ft_parse_io_redir(node, list_token))
			return (0);
	}
	else
	{
		if (!add_word_node(node, *list_token))
			return (0);
		ft_next_token(list_token);
	}
	return (1);
}

int	add_word_node(t_node *node, t_token *token)
{
	char	**tmp_raw_args;
	int		count;
	int		i;

	count = 0;
	if (node->args)
		while (node->args[count])
			count++;
	tmp_raw_args = malloc(sizeof(char *) * (count + 2));
	if (!tmp_raw_args)
		return (0);
	i = -1;
	while (++i < count)
		tmp_raw_args[i] = node->args[i];
	tmp_raw_args[i] = ft_strdup(token->value);
	if (!tmp_raw_args[i])
		return (free(tmp_raw_args), 0);
	tmp_raw_args[i + 1] = NULL;
	if (node->args)
		free(node->args);
	node->args = tmp_raw_args;
	return (1);
}

int	ft_count_args(t_token *list_token)
{
	int	count;

	count = 0;
	while (list_token && list_token->type == T_WORD)
	{
		count++;
		list_token = list_token->next;
	}
	return (count);
}

int	ft_parse_args(t_node *node, t_token **list_token, t_minishell *shell)
{
	int		arg_count;
	int		i;
	char	**tmp_arg;

	arg_count = ft_count_args(*list_token);
	if (arg_count == 0)
		return (1);
	tmp_arg = (char **)malloc(sizeof(char *) * (arg_count + 1));
	if (!tmp_arg)
		return (0);
	i = 0;
	while (*list_token && (*list_token)->type == T_WORD)
	{
		tmp_arg[i] = ft_strdup((*list_token)->value);
		if (!tmp_arg[i])
			return (ft_free_tmp_arg(tmp_arg, i), 0);
		i++;
		ft_next_token(list_token);
	}
	tmp_arg[i] = NULL;
	node->expand_args = expand_args(tmp_arg, shell);
	free_split(tmp_arg);
	if (!node->expand_args)
		return (0);
	return (1);
}

int	ft_parse_io_redir(t_node *node, t_token **list_token)
{
	t_token_type	redir_type;
	t_io_node		*tmp;
	int				fd;

	while (*list_token && ft_is_redirection((*list_token)->type))
	{
		redir_type = (*list_token)->type;
		fd = (*list_token)->fd;
		ft_next_token(list_token);
		if (!list_token)
			return (0);
		if ((*list_token)->type != T_WORD)
			return (0);
		tmp = ft_create_io_node(ft_token_to_io_type(redir_type),
				(*list_token)->value, fd);
		if (!tmp)
			return (0);
		ft_add_io_node(&node->io_list, tmp);
		ft_next_token(list_token);
	}
	return (1);
}
