/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 04:23:08 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:29:46 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_operator(t_token_type type)
{
	if (type == T_PIPE || type == T_AND || type == T_OR)
		return (1);
	return (0);
}

int	ft_is_redirection(t_token_type type)
{
	if (type == T_LESS || type == T_GREAT || type == T_DLESS
		|| type == T_DGREAT)
		return (1);
	return (0);
}

void	ft_print_syntax_error(char *token_str)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (token_str)
		ft_putstr_fd(token_str, 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putstr_fd("'\n", 2);
}

char	*ft_get_token_str(t_token_type type)
{
	if (type == T_PIPE)
		return ("|");
	else if (type == T_AND)
		return ("&&");
	else if (type == T_OR)
		return ("||");
	else if (type == T_LESS)
		return ("<");
	else if (type == T_GREAT)
		return (">");
	else if (type == T_DLESS)
		return ("<<");
	else if (type == T_DGREAT)
		return (">>");
	else if (type == T_OPEN_PARENT)
		return ("(");
	else if (type == T_CLOSE_PARENT)
		return (")");
	return ("unknown");
}

int	ft_check_first_token(t_token *tokens)
{
	if (!tokens)
		return (1);
	if (ft_is_operator(tokens->type))
	{
		ft_print_syntax_error(ft_get_token_str(tokens->type));
		return (0);
	}
	if (tokens->type == T_CLOSE_PARENT)
	{
		ft_print_syntax_error(")");
		return (0);
	}
	return (1);
}
