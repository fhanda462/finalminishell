/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:46:53 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:29:38 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lexer(char *line)
{
	t_token	*token_list;
	int		error;

	error = 0;
	token_list = NULL;
	while (*line)
	{
		if (error)
			return (ft_clear_all_token(&token_list), NULL);
		while (*line && ft_isspace(*line))
			line++;
		if (!*line)
			break ;
		error = (!process_token(&line, &token_list));
	}
	if (token_list && !ft_validate_syntax(token_list))
		return (ft_clear_all_token(&token_list), NULL);
	return (token_list);
}

int	process_token(char **line, t_token **token_list)
{
	if (!ft_strncmp(*line, "<<", 2) || !ft_strncmp(*line, ">>", 2)
		|| !ft_strncmp(*line, "&&", 2) || !ft_strncmp(*line, "||", 2))
		return (ft_handle_separator(line, token_list));
	if (ft_is_fd_redirection(*line))
		return (ft_handle_fd_redirection(line, token_list));
	if (**line == '<' || **line == '>' || **line == '|' || **line == '('
		|| **line == ')')
		return (ft_handle_separator(line, token_list));
	return (ft_append_word(line, token_list));
}

int	ft_is_fd_redirection(char *line)
{
	int	i;

	i = 0;
	if (!ft_isdigit(line[i]))
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == '>' || line[i] == '<')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_handle_separator(char **ptr_line, t_token **token_list)
{
	if (!ft_strncmp(*ptr_line, "<<", 2))
		return (ft_append_separator(T_DLESS, ptr_line, token_list));
	else if (!ft_strncmp(*ptr_line, ">>", 2))
		return (ft_append_separator(T_DGREAT, ptr_line, token_list));
	else if (!ft_strncmp(*ptr_line, "<", 1))
		return (ft_append_separator(T_LESS, ptr_line, token_list));
	else if (!ft_strncmp(*ptr_line, ">", 1))
		return (ft_append_separator(T_GREAT, ptr_line, token_list));
	else if (!ft_strncmp(*ptr_line, "(", 1))
		return (ft_append_separator(T_OPEN_PARENT, ptr_line, token_list));
	else if (!ft_strncmp(*ptr_line, ")", 1))
		return (ft_append_separator(T_CLOSE_PARENT, ptr_line, token_list));
	else if (!ft_strncmp(*ptr_line, "&&", 2))
		return (ft_append_separator(T_AND, ptr_line, token_list));
	else if (!ft_strncmp(*ptr_line, "||", 2))
		return (ft_append_separator(T_OR, ptr_line, token_list));
	else
		return (ft_append_separator(T_PIPE, ptr_line, token_list));
}
