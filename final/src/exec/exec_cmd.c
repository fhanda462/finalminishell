/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:46:56 by hazali            #+#    #+#             */
/*   Updated: 2026/03/13 11:56:31 by hazali           ###   ########.fr       */
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

	if (cmd_node->io_list)
	{
		fd_stdin = dup(STDIN_FILENO);
		fd_stdout = dup(STDOUT_FILENO);
		if (handle_redir(cmd_node->io_list) == -1)
		{
			reset_fds_std(fd_stdin, fd_stdout);
			return (1);
		}
	}
	exit = ft_exec_builtin(cmd_node->expand_args, shell);
	if (cmd_node->io_list)
		reset_fds_std(fd_stdin, fd_stdout);
	return (exit);
}

static void	child_exec(t_node *cmd_node, t_minishell *shell)
{
	char	*cmd_path;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	cmd_path = get_cmd_path(cmd_node->expand_args[0], shell->environ);
	if (!cmd_path)
	{
		exec_error(cmd_node->expand_args[0], "command not found");
		exit(127);
	}
	execve(cmd_path, cmd_node->expand_args, shell->environ);
	perror(cmd_node->expand_args[0]);
	exit(126);
}

int	exec_extrn_cmd(t_node *cmd_node, t_minishell *shell)
{
	pid_t				pid;
	int					status;
	struct sigaction	sa;
	struct sigaction	sa_old;

	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
		child_exec(cmd_node, shell);
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, &sa_old);
	waitpid(pid, &status, 0);
	sigaction(SIGINT, &sa_old, NULL);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
		write(STDOUT_FILENO, "Quit (core dumped)\n", 21);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		return (g_signal_received = SIGINT, write(1, "\n", 1), 130);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
