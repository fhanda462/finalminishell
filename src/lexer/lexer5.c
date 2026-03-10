/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 04:22:30 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:29:45 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_append_separator(t_token_type type, char **ptr_line,
		t_token **token_list)
{
	t_token	*token;

	token = ft_new_token(NULL, type);
	if (type == T_GREAT || type == T_DGREAT)
		token->fd = 1;
	else if (type == T_LESS || type == T_DLESS)
		token->fd = 0;
	if (!token)
		return (0);
	ft_add_token(token_list, token);
	(*ptr_line)++;
	if (type == T_DGREAT || type == T_DLESS || type == T_OR || type == T_AND)
		(*ptr_line)++;
	return (1);
}

int	ft_append_word(char **ptr_line, t_token **token_list)
{
	char	*tmp_line;
	char	*value;
	t_token	*token;
	size_t	i;

	tmp_line = *ptr_line;
	i = 0;
	while (tmp_line[i] && !ft_is_separator(tmp_line + i))
	{
		if (ft_is_quote(tmp_line[i]))
		{
			if (!ft_skip_quotes(tmp_line, &i))
				return (ft_print_quote_err(tmp_line[i]), 0);
		}
		else
			i++;
	}
	value = ft_substr(tmp_line, 0, i);
	if (!value)
		return (0);
	token = ft_new_token(value, T_WORD);
	if (!token)
		return (free(value), 0);
	*ptr_line += i;
	return (ft_add_token(token_list, token), 1);
}

void	print_tokens(t_token *tokens)
{
	t_token				*curr;
	static const char	*type_names[] = {"WORD", "LESS", "GREAT", "DLESS",
		"DGREAT", "PIPE", "OPEN_PARENT", "CLOSE_PARENT", "AND", "OR"};

	curr = tokens;
	printf("=== TOKENS ===\n");
	while (curr)
	{
		printf("[%s]", type_names[curr->type]);
		if (curr->value)
			printf(" '%s'", curr->value);
		if (curr->fd > 0)
			printf(" (fd: %d)", curr->fd);
		printf("\n");
		curr = curr->next;
	}
	printf("==============\n");
}
