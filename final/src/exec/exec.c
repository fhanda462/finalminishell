/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:47:01 by hazali            #+#    #+#             */
/*   Updated: 2026/03/13 11:43:11 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_execute(t_node *ast, t_minishell *shell)
{
	if (!ast)
		return (1);
	if (ast->type == N_PIPE)
		return (exec_pipe(ast, shell));
	else if (ast->type == N_CMD)
	{
		if (ast->io_list)
			return (exec_redir_cmd(ast, shell));
		return (exec_simple_cmd(ast, shell));
	}
	else if (ast->type == N_AND || ast->type == N_OR)
		return (exec_and_or(ast, shell));
	return (1);
}

int	exec_redir_cmd(t_node *cmd_node, t_minishell *shell)
{
	int		saved_stdin;
	int		saved_stdout;
	int		ret;
	char	**expanded_args;

	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	if (handle_redir(cmd_node->io_list) == -1)
		return (reset_fds_std(saved_stdin, saved_stdout), 1);
	if (!cmd_node->args)
		return (reset_fds_std(saved_stdin, saved_stdout), 0);
	expanded_args = expand_args(cmd_node->args, shell);
	if (!expanded_args || !expanded_args[0])
	{
		if (expanded_args)
			free_split(expanded_args);
		return (reset_fds_std(saved_stdin, saved_stdout), 0);
	}
	if (ft_is_builtin(expanded_args[0]))
		ret = handle_builtin(cmd_node, shell);
	else
		ret = exec_extrn_cmd(cmd_node, shell);
	reset_fds_std(saved_stdin, saved_stdout);
	free_split(expanded_args);
	return (ret);
}
