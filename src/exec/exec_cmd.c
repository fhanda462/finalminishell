/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:46:56 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:29:33 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtins.h"
#include "../../inc/minishell.h"

// int	exec_simple_cmd(t_node *cmd_node, t_minishell *shell)
// {

// 	if (!cmd_node || !cmd_node->expand_args || !cmd_node->expand_args[0])
// 		return (0);
// 	if (ft_is_builtin(cmd_node->expand_args[0]))
// 		return (handle_builtin(cmd_node, shell));
// 	else
// 		return (exec_extrn_cmd(cmd_node, shell));
// }

int	exec_simple_cmd(t_node *cmd_node, t_minishell *shell)
{
	char	**expanded_args;
	int		ret;

	if (!cmd_node || !cmd_node->args)
		return (0);
	expanded_args = expand_args(cmd_node->args, shell);
	if (!expanded_args || !expanded_args[0])
	{
		if (expanded_args)
			free_split(expanded_args);
		return (0);
	}
	if (ft_is_builtin(expanded_args[0]))
		ret = handle_builtin(cmd_node, shell);
	else
		ret = exec_extrn_cmd(cmd_node, shell);
	free_split(expanded_args);
	return (ret);
}

int	handle_builtin(t_node *cmd_node, t_minishell *shell)
{
	int	fd_stdin;
	int	fd_stdout;
	int	exit;

	fd_stdin = dup(STDIN_FILENO);
	fd_stdout = dup(STDOUT_FILENO);
	if (handle_redir(cmd_node->io_list) == -1)
	{
		reset_fds_std(fd_stdin, fd_stdout);
		return (1);
	}
	exit = ft_exec_builtin(cmd_node->expand_args, shell);
	reset_fds_std(fd_stdin, fd_stdout);
	return (exit);
}

int	exec_extrn_cmd(t_node *cmd_node, t_minishell *shell)
{
	pid_t	pid;
	int		status;
	char	*cmd_path;

	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
	{
		if (handle_redir(cmd_node->io_list) == -1)
			exit(1);
		cmd_path = get_cmd_path(cmd_node->expand_args[0], shell->environ);
		if (!cmd_path)
		{
			exec_error(cmd_node->expand_args[0], "command not found");
			exit(127);
		}
		execve(cmd_path, cmd_node->expand_args, shell->environ);
		perror("126");
		exit(126);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
