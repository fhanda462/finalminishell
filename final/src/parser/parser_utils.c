/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:32:23 by hazali            #+#    #+#             */
/*   Updated: 2026/02/26 02:32:57 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_syntax_error(t_token_type type)
{
	ft_putstr_fd("minishell: Syntax error near unexpected token `",
		STDERR_FILENO);
	if (type == T_EOF)
		ft_putstr_fd("newline", STDERR_FILENO);
	else
		ft_putstr_fd(ft_get_token_str(type), STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
}

t_node_type	ft_token_to_node_type(t_token_type type)
{
	if (type == T_PIPE)
		return (N_PIPE);
	else if (type == T_AND)
		return (N_AND);
	else if (type == T_OR)
		return (N_OR);
	else if (type == T_LESS)
		return (N_REDIR_IN);
	else if (type == T_GREAT)
		return (N_REDIR_OUT);
	else if (type == T_DLESS)
		return (N_HEREDOC);
	else if (type == T_DGREAT)
		return (N_APPEND);
	return (N_CMD);
}

t_io_type	ft_token_to_io_type(t_token_type type)
{
	if (type == T_LESS)
		return (IO_IN);
	else if (type == T_GREAT)
		return (IO_OUT);
	else if (type == T_DLESS)
		return (IO_HEREDOC);
	else if (type == T_DGREAT)
		return (IO_APPEND);
	return (IO_OUT);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	free_io_list(t_io_node *io_list)
{
	t_io_node	*current;
	t_io_node	*temp;

	current = io_list;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp->value);
		free(temp);
	}
}
