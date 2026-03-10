/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:46:40 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:31:03 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_node	*ft_parsing(t_token *list_token, t_minishell *shell)
{
	t_token	*curren_list;
	t_node	*ast;

	curren_list = list_token;
	if (!curren_list)
		return (NULL);
	ast = ft_parse_expression(&curren_list, 0, shell);
	if (!ast || curren_list)
	{
		ft_clear_ast(&ast);
		return (NULL);
	}
	return (ast);
}

t_node	*ft_parse_expression(t_token **list_token, int precedence,
		t_minishell *shell)
{
	t_node			*left;
	t_node			*right;
	int				curr_precedence;
	t_token_type	type_operator;

	if (!*list_token)
		return (NULL);
	left = ft_parse_primary(list_token, shell);
	if (!left)
		return (NULL);
	while (*list_token && ft_is_operator((*list_token)->type)
		&& (ft_get_precedence((*list_token)->type)) >= precedence)
	{
		type_operator = (*list_token)->type;
		curr_precedence = ft_get_precedence(type_operator);
		ft_next_token(list_token);
		right = ft_parse_expression(list_token, curr_precedence + 1, shell);
		if (!right)
			return (ft_clear_ast(&left), NULL);
		left = ft_create_node(ft_token_to_node_type(type_operator), left,
				right);
		if (!left)
			return (ft_clear_ast(&right), ft_clear_ast(&left), NULL);
	}
	return (left);
}

t_node	*ft_parse_parentheses(t_token **list_token, t_minishell *shell)
{
	t_node	*node;

	ft_next_token(list_token);
	node = ft_parse_expression(list_token, 0, shell);
	if (!node || ((*list_token) && (*list_token)->type != T_CLOSE_PARENT))
	{
		ft_putendl_fd("minishell: Syntax error: expected ')'", STDERR_FILENO);
		ft_clear_ast(&node);
		return (NULL);
	}
	ft_next_token(list_token);
	return (node);
}

t_node	*ft_parse_primary(t_token **list_token, t_minishell *shell)
{
	if (!*list_token)
	{
		ft_putendl_fd("minishell: Syntax error: unexpected end of input",
			STDERR_FILENO);
		return (NULL);
	}
	if ((*list_token)->type == T_OPEN_PARENT)
	{
		return (ft_parse_parentheses(list_token, shell));
	}
	else if ((*list_token)->type == T_WORD
		|| ft_is_redirection((*list_token)->type))
	{
		return (ft_parse_command(list_token, shell));
	}
	return (ft_putendl_fd("minishell: Syntax error: unexpected token",
			STDERR_FILENO), NULL);
}

// // t_node	*ft_parse_command(t_token **list_token,
// 		t_minishell *shell) VERSION AVTN CORRECTION POUR LES REDIRECTION
// // {
// // 	t_node	*node;

// // 	node = ft_create_cmd_node();
// // 	if (!node)
// // 		return (NULL);
// // 	while (*list_token && ((*list_token)->type == T_WORD
// // 			|| ft_is_redirection((*list_token)->type)))
// // 	{
// // 		if (!ft_parse_word_redir(node, list_token, shell))
// // 		{
// // 			ft_clear_ast(&node);
// // 			return (NULL);
// // 		}
// // 		if (*list_token && ((*list_token)->type == T_WORD
// 				|| ft_is_redirection((*list_token)->type)))
// // 			continue ;
// // 		break ;
// // 	}
// // 	return (node);
// // }

// // int	ft_parse_word_redir(t_node *node, t_token **list_token,
// 		t_minishell *shell)
// // {
// // 	if (ft_is_redirection((*list_token)->type))
// // 	{
// // 		if (!ft_parse_io_redir(node, list_token))
// 			return (0);
// 	}
// 	else
// 	{
// 		if (!ft_parse_args(node, list_token, shell))
// 			return (0);
// 	}
// 	return (1);
// }

t_node	*ft_parse_command(t_token **list_token, t_minishell *shell)
{
	t_node	*node;

	node = ft_create_cmd_node();
	if (!node)
		return (NULL);
	while (*list_token && ((*list_token)->type == T_WORD
			|| ft_is_redirection((*list_token)->type)))
	{
		if (!ft_parse_word_redir(node, list_token))
		{
			ft_clear_ast(&node);
			return (NULL);
		}
	}
	if (node->args)
	{
		node->expand_args = expand_args(node->args, shell);
		if (!node->expand_args)
		{
			ft_clear_ast(&node);
			return (NULL);
		}
	}
	return (node);
}

// int	ft_parse_io_redir(t_node *node, t_token **list_token) V0
// {
// 	t_io_node	*io_node;

// 	io_node = ft_create_io_node(ft_token_to_io_type((*list_token)->type),
// 			(*list_token)->value);
// 	if (!io_node)
// 		return (0);
// 	ft_add_io_node(&node->io_list, io_node);
// 	ft_next_token(list_token);
// 	if (!*list_token || (*list_token)->type != T_WORD)
// 	{
// 		ft_putendl_fd("minishell: Syntax error: expected
//  	filename after redirection",STDERR_FILENO);
// 		return (0);
// 	}
// 	return (1);
// }
