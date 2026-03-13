/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:50:20 by hazali            #+#    #+#             */
/*   Updated: 2026/02/26 02:47:45 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include "minishell.h"

typedef enum e_io_type
{
	IO_IN,
	IO_OUT,
	IO_HEREDOC,
	IO_APPEND
}						t_io_type;

typedef enum e_node_type
{
	N_CMD,
	N_PIPE,
	N_AND,
	N_OR,
	N_REDIR_IN,
	N_REDIR_OUT,
	N_HEREDOC,
	N_APPEND
}						t_node_type;

typedef struct s_io_node
{
	t_io_type			type;
	char				*value;
	int					fd;
	struct s_io_node	*next;
}						t_io_node;

typedef struct s_node
{
	t_node_type			type;
	t_io_node			*io_list;
	char				**args;
	char				**expand_args;
	struct s_node		*left;
	struct s_node		*right;
}						t_node;

t_node					*ft_parsing(t_token *list_token, t_minishell *shell);
t_node					*ft_parse_expression(t_token **list_token,
							int precedence, t_minishell *shell);
t_node					*ft_parse_parentheses(t_token **list_token,
							t_minishell *shell);
t_node					*ft_parse_primary(t_token **list_token,
							t_minishell *shell);
t_node					*ft_parse_command(t_token **list_token,
							t_minishell *shell);
t_io_node				*ft_create_io_node(t_io_type type, char *value, int fd);
t_node					*ft_create_cmd_node(void);
int						ft_parse_word_redir(t_node *node, t_token **list_token);

int						ft_parse_args(t_node *node, t_token **list_token,
							t_minishell *shell);
int						ft_count_args(t_token *list_token);
t_node_type				ft_token_to_node_type(t_token_type type);
void					ft_add_io_node(t_io_node **io_list, t_io_node *new_io);
void					free_args(char **args);
void					free_io_list(t_io_node *io_list);
void					ft_clear_ast(t_node **ast);
int						ft_get_precedence(t_token_type type);
void					ft_next_token(t_token **list_token);
t_node					*ft_create_node(t_node_type type, t_node *left,
							t_node *right);
int						ft_parse_io_redir(t_node *node, t_token **list_token);
t_node_type				ft_token_to_node_type(t_token_type type);
t_io_type				ft_token_to_io_type(t_token_type type);
char					*expand_variables(char *input, t_minishell *shell);
void					print_ast_recursive(t_node *node, int depth,
							char *prefix);
int						add_word_node(t_node *node, t_token *token);
void					ft_free_expandes_args(char **expanded_args, int i);

#endif