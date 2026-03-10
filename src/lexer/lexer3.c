/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:40:49 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:29:43 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

int	ft_skip_quotes(char *line, size_t *i)
{
	char	quote;

	quote = line[*i];
	if (ft_strchr(line + *i + 1, quote))
	{
		(*i)++;
		while (line[*i] != quote)
			(*i)++;
		(*i)++;
		return (1);
	}
	return (0);
}

void	ft_print_quote_err(char c)
{
	ft_putstr_fd("minishell: unexpected EOF while looking for matching `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
}

void	ft_clear_all_token(t_token **lst)
{
	t_token	*current;
	t_token	*next;

	current = *lst;
	if (!current)
		return ;
	while (current)
	{
		free(current->value);
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

int	ft_is_separator(char *s)
{
	if (!ft_strncmp(s, "&&", 2) || *s == ' ' || *s == '\t' || *s == '<'
		|| *s == '>' || *s == '|' || *s == '(' || *s == ')')
		return (1);
	return (0);
}
