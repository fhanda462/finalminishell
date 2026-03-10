/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 04:26:54 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:30:32 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

typedef struct s_env	t_env;

int						ft_strcmp(char *s1, char *s2);
void					free_split(char **split);
int						count_args(char **args);
void					exec_error(char *cmd, char *msg);
void					exit_with_error(char *msg, int code);

void					ft_print_ast(t_node *ast);
t_env					*init_env_list(char **envp);

char					*get_var_value(char *var_name, t_minishell *shell);
int						is_special_char(char c);
char					*extract_var_name(char *str, int *index);
char					*ft_strjoin_char(char *s, char c);
char					**expand_args(char **args, t_minishell *shell);

char					*remove_quotes(char *str);
char					**remove_empty_args(char **args);
t_env					*create_env_node(char *env_str);
void					add_env_node(t_env **env_list, t_env *new_node);
char					**cpy_non_empty_args(char **args, char **result);
void					ft_free_tmp_arg(char **tmp_arg, int i);
void					free_env_list(t_env **env_list);

void					handle_sigint(int sig);
void					setup_signals(void);

#endif