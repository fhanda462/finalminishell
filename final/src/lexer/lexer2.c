/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:46:49 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:29:39 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_fd_redirection(char **line, t_token **list)
{
	int		fd;
	int		i;
	char	*start;
	t_token	*token;

	i = 0;
	start = *line;
	while (ft_isdigit((*line)[i]))
		i++;
	fd = ft_atoi(start);
	*line += i;
	token = get_redir_token(line);
	if (!token)
		return (0);
	token->fd = fd;
	ft_add_token(list, token);
	advance_redir_line(line);
	return (1);
}

void	advance_redir_line(char **line)
{
	if (!ft_strncmp(*line, ">>", 2) || !ft_strncmp(*line, "<<", 2))
		*line += 2;
	else
		(*line)++;
}

t_token	*get_redir_token(char **line)
{
	if (!ft_strncmp(*line, ">>", 2))
		return (ft_new_token(NULL, T_DGREAT));
	else if (!ft_strncmp(*line, "<<", 2))
		return (ft_new_token(NULL, T_DLESS));
	else if (**line == '>')
		return (ft_new_token(NULL, T_GREAT));
	else if (**line == '<')
		return (ft_new_token(NULL, T_LESS));
	else
		return (NULL);
}

t_token	*ft_new_token(char *value, t_token_type type)
{
	t_token	*new_token;

	new_token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = value;
	new_token->type = type;
	new_token->fd = -1;
	return (new_token);
}

void	ft_add_token(t_token **lst, t_token *new_token)
{
	t_token	*current;

	if (!*lst)
	{
		*lst = new_token;
		return ;
	}
	current = *lst;
	while (current && current->next)
	{
		current = current->next;
	}
	current->next = new_token;
	new_token->prev = current;
}
