/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:03:10 by hammm             #+#    #+#             */
/*   Updated: 2026/03/08 17:29:44 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_last_token(t_token *tokens)
{
	t_token	*curr;

	if (!tokens)
		return (1);
	curr = tokens;
	while (curr->next)
		curr = curr->next;
	if (ft_is_operator(curr->type))
	{
		ft_print_syntax_error(ft_get_token_str(curr->type));
		return (0);
	}
	if (ft_is_redirection(curr->type))
	{
		ft_print_syntax_error(NULL);
		return (0);
	}
	return (1);
}

static int	ft_check_consecutive_tokens(t_token *curr)
{
	if (ft_is_operator(curr->type) && ft_is_operator(curr->next->type))
	{
		ft_print_syntax_error(ft_get_token_str(curr->next->type));
		return (0);
	}
	if (ft_is_redirection(curr->type))
	{
		if (curr->next->type != T_WORD)
		{
			ft_print_syntax_error(ft_get_token_str(curr->next->type));
			return (0);
		}
	}
	return (1);
}

static int	check_open_parent(t_token *curr)
{
	if (!curr->next || curr->next->type == T_CLOSE_PARENT)
		return (ft_print_syntax_error(")"), 0);
	if (curr->next && ft_is_operator(curr->next->type))
		return (ft_print_syntax_error(ft_get_token_str(curr->next->type)), 0);
	return (1);
}

static int	ft_check_parentheses(t_token *tokens)
{
	t_token	*curr;
	int		open_count;

	open_count = 0;
	curr = tokens;
	while (curr)
	{
		if (curr->type == T_OPEN_PARENT)
		{
			open_count++;
			if (!check_open_parent(curr))
				return (0);
		}
		else if (curr->type == T_CLOSE_PARENT)
		{
			open_count--;
			if (open_count < 0)
				return (ft_print_syntax_error(")"), 0);
		}
		curr = curr->next;
	}
	if (open_count != 0)
		return (ft_print_syntax_error("("), 0);
	return (1);
}

int	ft_validate_syntax(t_token *tokens)
{
	t_token	*curr;

	if (!ft_check_first_token(tokens))
		return (0);
	if (!ft_check_last_token(tokens))
		return (0);
	if (!ft_check_parentheses(tokens))
		return (0);
	curr = tokens;
	while (curr && curr->next)
	{
		if (!ft_check_consecutive_tokens(curr))
			return (0);
		curr = curr->next;
	}
	return (1);
}
