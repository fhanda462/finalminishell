/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 02:29:19 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:22:10 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_minishell	t_minishell;

int							ft_is_builtin(char *cmd);

int							ft_exec_builtin(char **args, t_minishell *shell);

int							ft_pwd(void);
int							ft_echo(char **args);
int							ft_cd(char **args, t_minishell *shell);
int							ft_export(char **args, t_minishell *shell);
int							ft_unset(char **args, t_minishell *shell);
int							ft_exit(char **args, t_minishell *shell);
int							ft_env(t_minishell *shell);

#endif