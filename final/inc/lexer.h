/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:05:00 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:26:45 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stddef.h>
# include <stdio.h>

typedef enum e_token_type
{
	T_WORD,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT,
	T_PIPE,
	T_OPEN_PARENT,
	T_CLOSE_PARENT,
	T_AND,
	T_OR,
	T_EOF
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	int				fd;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

t_token				*ft_lexer(char *line);
void				ft_clear_all_token(t_token **lst);
t_token				*ft_new_token(char *value, t_token_type type);
int					ft_isspace(char c);
int					ft_handle_separator(char **ptr_line, t_token **token_list);
int					ft_append_separator(t_token_type type, char **ptr_line,
						t_token **token_list);
void				ft_add_token(t_token **lst, t_token *new_token);
int					ft_is_separator(char *s);
int					ft_is_quote(char c);
int					ft_skip_quotes(char *line, size_t *i);
void				ft_print_quote_err(char c);
int					ft_append_word(char **ptr_line, t_token **token_list);
void				print_tokens(t_token *tokens);
int					ft_validate_syntax(t_token *tokens);
int					ft_is_operator(t_token_type type);
int					ft_is_redirection(t_token_type type);
char				*ft_get_token_str(t_token_type type);
int					ft_handle_fd_redirection(char **line, t_token **list);
int					ft_is_fd_redirection(char *line);
int					process_token(char **line, t_token **token_list);
void				advance_redir_line(char **line);
t_token				*get_redir_token(char **line);
void				ft_print_syntax_error(char *token_str);
int					ft_check_first_token(t_token *tokens);

#endif