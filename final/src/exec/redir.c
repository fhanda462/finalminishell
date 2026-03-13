/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazali <hazali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:34:02 by hazali            #+#    #+#             */
/*   Updated: 2026/03/13 11:02:18 by hazali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	open_redir_file(t_io_node *redir)
{
	int	fd;

	if (redir->type == IO_IN)
		fd = open(redir->value, O_RDONLY);
	else if (redir->type == IO_OUT)
		fd = open(redir->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == IO_APPEND)
		fd = open(redir->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (redir->type == IO_HEREDOC)
		fd = handle_hd(redir->value);
	else
		return (-1);
	if (fd == -1 && redir->type != IO_HEREDOC)
		perror(redir->value);
	return (fd);
}

int	handle_redir(t_io_node *io_list)
{
	t_io_node	*curr;
	int			fd;

	curr = io_list;
	while (curr)
	{
		fd = open_redir_file(curr);
		if (fd == -1)
			return (-1);
		if (curr->type == IO_IN || curr->type == IO_HEREDOC)
		{
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		else if (curr->type == IO_OUT || curr->type == IO_APPEND)
		{
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		curr = curr->next;
	}
	return (0);
}

void	reset_fds_std(int fd_stdin, int fd_stdout)
{
	if (fd_stdin != -1)
	{
		dup2(fd_stdin, STDIN_FILENO);
		close(fd_stdin);
	}
	if (fd_stdout != -1)
	{
		dup2(fd_stdout, STDOUT_FILENO);
		close(fd_stdout);
	}
}
