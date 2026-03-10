/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:34:25 by hazali            #+#    #+#             */
/*   Updated: 2026/02/25 04:31:16 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "parser.h"

int		ft_execute(t_node *ast, t_minishell *shell);
int		exec_simple_cmd(t_node *cmd_node, t_minishell *shell);
int		handle_builtin(t_node *cmd_node, t_minishell *shell);
int		open_redir_file(t_io_node *redir);
int		handle_redir(t_io_node *io_list);
void	reset_fds_std(int fd_stdin, int fd_stdout);
int		handle_hd(char *delimiter);
int		exec_pipe(t_node *pipe_node, t_minishell *shell);
int		exec_extrn_cmd(t_node *cmd_node, t_minishell *shell);
int		exec_and_or(t_node *node, t_minishell *shell);
char	*get_cmd_path(char *cmd, char **envp);
char	*build_full_path(char *dir, char *cmd);
char	**get_paths_env(char **envp);
int		ft_is_builtin(char *cmd);
int		ft_exec_builtin(char **args, t_minishell *shell);
void	ft_close_pipes(int pipefd1, int pipefd2);

#endif