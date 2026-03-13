/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:34:08 by hazali            #+#    #+#             */
/*   Updated: 2026/03/08 17:29:34 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exec_child_left(t_node *left, int *pipefd, t_minishell *shell)
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	exit(ft_execute(left, shell));
}

void	exec_child_right(t_node *right, int *pipefd, t_minishell *shell)
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	exit(ft_execute(right, shell));
}

int	exec_pipe(t_node *pipe_node, t_minishell *shell)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;
	int		exit;

	exit = 0;
	if (pipe(pipefd) == -1)
		return (perror("pipe"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork"), 1);
	if (pid1 == 0)
		exec_child_left(pipe_node->left, pipefd, shell);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork"), 1);
	if (pid2 == 0)
		exec_child_right(pipe_node->right, pipefd, shell);
	ft_close_pipes(pipefd[0], pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		exit = WEXITSTATUS(status);
	return (exit);
}

void	ft_close_pipes(int pipefd1, int pipefd2)
{
	close(pipefd1);
	close(pipefd2);
}
